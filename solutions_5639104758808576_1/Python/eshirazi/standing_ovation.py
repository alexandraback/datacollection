from math import sqrt
import numpy
import StringIO


def solve_case(case_index, inp):
    standing = 0
    missing = 0
    
    for i, count in enumerate(inp):
        if standing < i:
            diff = i - standing
            missing += diff
            standing += diff
        standing += count

    return missing
        

def solve(cases):
    ret = ""

    for i, case in enumerate(cases, start = 1):
        ret += "Case #%d: %s\n" % (i, solve_case(i, case))

    return ret

test_inp = StringIO.StringIO(
"""4
4 11111
1 09
5 110011
0 1""")

def parse_case(i, inp):
    max_shy, s = inp.readline().split()[:2]
    max_shy = int(max_shy)
    
    return [
            int(digit)
            for digit
            in s[:max_shy + 1]
        ]

def parse_input(inp):
    num_cases = int(inp.readline().strip())
    cases = []
    for i in xrange(1, num_cases + 1):
        cases.append(parse_case(i, inp))
    return cases

#print solve(parse_input(test_inp))

#open("A-small-attempt0.out", "w").write(
#    solve(parse_input(open("./A-small-attempt0.in", "r")))
#)

open("A-large.out", "w").write(
    solve(parse_input(open("./A-large.in", "r")))
)
