from math import sqrt
import numpy
import StringIO


def check_time_silence(diners, time, silence):
    remain = time - silence
    return sum(max(diner - 1, 0) / remain for diner in diners) <= silence

def check_time(diners, time):
    for silence in xrange(time):
        if check_time_silence(diners, time, silence):
            return True
    return False

def solve_case(case_index, diners):
    if check_time(diners, 0):
        return 0

    upper = max(diners)
    lower = 0

    while upper - lower > 1:
        mid = (lower + upper) / 2

        if check_time(diners, mid):
            upper = mid
        else:
            lower = mid

    return upper
        

def solve(cases):
    ret = ""

    for i, case in enumerate(cases, start = 1):
        ret += "Case #%d: %s\n" % (i, solve_case(i, case))

    return ret

test_inp = StringIO.StringIO(
"""3
1
3
4
1 2 1 2
1
4""")

def parse_case(i, inp):
    D = int(inp.readline())
    diners = map(int, inp.readline().split())[:D]
    
    return diners

def parse_input(inp):
    num_cases = int(inp.readline().strip())
    cases = []
    for i in xrange(1, num_cases + 1):
        cases.append(parse_case(i, inp))
    return cases

print solve(parse_input(test_inp))

open("B-small-attempt0.out", "w").write(
    solve(parse_input(open("./B-small-attempt0.in", "r")))
)

#open("A-large.out", "w").write(
#    solve(parse_input(open("./A-large.in", "r")))
#)
