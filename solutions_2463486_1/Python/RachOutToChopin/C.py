#!/usr/bin/python
import math
import string
import sys

def solve(line):
    (a, b) = [ int(x) for x in line.split() ]
    return len([ x for x in table if x >= a and x <= b ])

f = open(sys.argv[1])
tblFile = open('C-table')
table = [ int(x.strip()) for x in tblFile.readlines() ]

NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    line = f.readline().strip()
    print "Case #%d: %s" % (qq+1, solve(line))
