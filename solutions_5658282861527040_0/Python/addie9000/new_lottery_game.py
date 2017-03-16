#!/usr/bin/python
import sys, math

#solve case function
def solve_case(abk, case_number):
    count = 0
    for a in range(0, abk[0]):
        for b in range(0, abk[1]):
            if a & b < abk[2]:
                count += 1
    print "Case #%d: %d" % (case_number, count)

#main
r = sys.stdin

if len(sys.argv) > 1:
    r = open(sys.argv[1], 'r')

total_cases = r.readline()
for case_number in range(1, int(total_cases) + 1):
    abk = map(int, r.readline().split(' '))
    solve_case(abk, case_number)