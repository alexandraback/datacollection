import fileinput 

def mult_pos(x, y):
    if x == '1': return y
    elif y == '1': return x
    elif x == y: return '-1'
    elif x == 'i': 
        if y == 'j': return 'k'
        elif y == 'k': return '-j'
        else: assert(False)
    elif x == 'j':
        if y == 'i': return '-k'
        elif y == 'k': return 'i'
        else: assert(False)
    elif x == 'k': 
        if y == 'i': return 'j'
        elif y == 'j': return '-i'
        else: assert(False)
    else: assert(False)

def strip_neg(x):
    if x[0] == '-': return (1, x[1])
    else: return (0, x)

def negate(x):
    if x[0] == '-': return x[1]
    else: return '-' + x

def mult(x, y):
    (x_neg, x_pos) = strip_neg(x)
    (y_neg, y_pos) = strip_neg(y)
    (z_neg, z_pos) = strip_neg(mult_pos(x_pos, y_pos))
    if (x_neg + y_neg + z_neg) % 2 == 1: return negate(z_pos)
    else: return z_pos

# all = ['1', 'i', 'j', 'k']
# for x in all:
#     for y in all:
#         y = negate(y)
#         print "%s x %s = %s" % (x, y, mult(x,y))

def mult_s(s):
    m = '1'
    for c in s:
        m = mult(m, c)
    return m

def product(s, X):
    m = mult_s(s)
    if m == '1': return 1
    elif m == '-1': 
        if X % 2 == 1: return '-1'
        else: return '1'
    else:
        n = X % 4
        if n == 1: return m
        elif n == 2: return '-1'
        elif n == 3: return negate(m)
        elif n == 0: return '1'
        else: assert(False)

def print_answer(case_num, answer):
    if answer: 
        print "Case #%d: %s" % (case_num, "YES")
    else: 
        print "Case #%d: %s" % (case_num, "NO")

def find(s, X, goal, swap_order):
    num_chars = 0
    m = '1'
    for i in range(min(X, 4)): # only loop up to 4 times
        for c in s:
            num_chars += 1
            if swap_order: 
                m = mult(c, m)
            else: 
                m = mult(m, c)
#            print "goal %s: %s at %d chars" % (goal, m, num_chars)
            if m == goal: return num_chars
    return -1

def find_i_from_left(s, X): return find(s, X, 'i', False)
def find_k_from_right(s, X): return find(s[::-1], X, 'k', True)

def do_case(case_num):
    [L, X] = [int(x) for x in next(input).split(' ')]
    s = next(input).rstrip()
    if product(s, X) != '-1':
        print_answer(case_num, False)
        return
    num_chars_to_i = find_i_from_left(s, X)
#    print "Num chars to i: %d" % num_chars_to_i
    if num_chars_to_i == -1: 
        print_answer(case_num, False)
        return
    num_chars_to_k = find_k_from_right(s, X)
#    print "Num chars to k: %d" % num_chars_to_k
    if num_chars_to_k == -1: 
        print_answer(case_num, False)
        return
    total_num_chars = L * X
    if (num_chars_to_i + num_chars_to_k) >= total_num_chars:
        print_answer(case_num, False)
        return
    else: 
        print_answer(case_num, True)
        return
        
    # i*j*k = -1
    # if product(s_in) = 1, impossible
    # if product(s_in) = -1 and X % 4 != 1 or 3, impossible
    # else, if X % 4 != 2, impossible
    print "Case #%d: L: %d, X: %d, s: %s" % (case_num, L, X, s)
    print "Mult %s" % product(s, X)

input = fileinput.input()
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

