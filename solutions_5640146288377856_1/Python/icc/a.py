#!/usr/bin/env python
from math import ceil
def solve(line):
    r,c,w = [int(x) for x in line.split()]
    return int(ceil(float(c)/float(w))) * (r - 1) + (int(ceil(float(c)/float(w))) - 1) + w

case_num = input()
for case in range(1, case_num + 1):
    line = raw_input()
    print("Case #%i: %i" % (case, solve(line)))

