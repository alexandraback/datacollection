from math import sqrt
import numpy
import StringIO

MULT = {
    ("1", "1"): "1",
    ("i", "1"): "i",
    ("j", "1"): "j",
    ("k", "1"): "k",
    ("1", "i"): "i",
    ("i", "i"): "-1",
    ("j", "i"): "k",
    ("k", "i"): "-j",
    ("1", "j"): "j",
    ("i", "j"): "-k",
    ("j", "j"): "-1",
    ("k", "j"): "i",
    ("1", "k"): "k",
    ("i", "k"): "j",
    ("j", "k"): "-i",
    ("k", "k"): "-1",
}

def neg(a):
    if a.startswith("-"):
        return a[-1]
    else:
        return "-" + a

def mult2(a,b):
    ret = MULT[(b[-1], a[-1])]
    if len(a) != len(b):
        ret = neg(ret)
    #    print a, "*", b, "=", ret
    return ret
        

def mult(*quats):
    return reduce(lambda x, y: mult2(x, y), quats, "1")

def pw(a, p):
    result = "1"

    c = a
    while p != 0:
        if p % 2 != 0:
            result = mult2(result, c)
        c = mult2(c, c)
        p /= 2

    return result    

def can_equal(c, total_length, target):
    all_c = mult(*c)

    last = "1"
    c_mult = {}

    for index, char in enumerate(c[:total_length]):
        last = mult2(last, char)
        if last not in c_mult or c_mult[last] > index:
            c_mult[last] = index
            
        if last == target:
            return index + 1

    index = len(c)
    cur_mul = all_c
    
    while index < total_length:
        last_mult = c_mult
        c_mult = dict(c_mult)

        for prev_quat, prev_index in last_mult.iteritems():
            cur_quat = mult2(cur_mul, prev_quat)
            cur_index = index + prev_index 
            
            if not cur_quat in c_mult or c_mult[cur_quat] > cur_index:
                c_mult[cur_quat] = cur_index
        
        if c_mult == last_mult:
            break
        
        cur_mul = mult2(cur_mul, all_c)
        index += len(c)
        
    ret = c_mult.get(target, total_length)

    if ret < total_length:
        return ret + 1

    return -1


def solve_case(case_index, c, x):
    single = mult(*c)

    if pw(single, x) != "-1":
        return "NO"

    total_length = len(c) * x

    i_index = can_equal(c, total_length, "i")

    if i_index == -1:
        return "NO"

    rotate_by = i_index % len(c)
    rot_c = c[rotate_by:] + c[:rotate_by]
    total_length -= i_index

    j_index = can_equal(rot_c, total_length, "j")

    if j_index == -1:
        return "NO"

    j_index += i_index

    #full_str = c * x
    #print full_str
    #print full_str[:i_index], "=", mult(*full_str[:i_index])
    #print " " * i_index + full_str[i_index:j_index], "=", mult(*full_str[i_index:j_index])

    return "YES"


def solve(cases):
    ret = ""

    for i, case in enumerate(cases, start = 1):
        l =  "Case #%d: %s\n" % (i, solve_case(i, case[0], case[1]))
        ret += l
        print l,

    print ""
    print "-------------------"
    print ""

    return ret

test_inp = StringIO.StringIO(
"""5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i""")

def parse_case(i, inp):
    L, X = map(int, inp.readline().split()[:2])
    chars = inp.readline()[:L]
    
    return chars, X

def parse_input(inp):
    num_cases = int(inp.readline().strip())
    cases = []
    for i in xrange(1, num_cases + 1):
        cases.append(parse_case(i, inp))
    return cases

#print solve(parse_input(test_inp))

#open("C-small-attempt0.out", "w").write(
#    solve(parse_input(open("./C-small-attempt0.in", "r")))
#)

open("C-large.out", "w").write(
    solve(parse_input(open("./C-large.in", "r")))
)
