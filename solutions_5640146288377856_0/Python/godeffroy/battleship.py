#!/usr/bin/python

import sys

def solve_case():
    (R,C,W)=[int(n) for n in sys.stdin.readline().split(" ")]
    moves=R*(C/W)+W
    if C%W==0: moves=moves-1
    return `moves`

cases_count=int(sys.stdin.readline())

for i in xrange(cases_count):
    print "Case #"+`i+1`+": "+solve_case()

