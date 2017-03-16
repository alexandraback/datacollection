#!/usr/bin/python

import sys, math

def isFair(n):
    var = str(n)
    lb = 0
    ub = len(var)-1
    while (lb < ub):
        if var[lb] != var [ub]:
            return False
        lb+=1
        ub-=1
    return True

def isSquare(n):
    prev = math.sqrt(n)
    n = float(n)
    while True:
        current = 0.5*(prev+n/prev)
        if abs(current-prev) < 1:
            break
        prev = current
    current = int(current)
    if current**2 != n:
        return False
    return isFair(current)

if len(sys.argv) != 2:
    print "Usage: ./fairsquare.py <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
line = 1
for test in range (1, ntests+1):
    info = data[line].strip().split()
    line+=1
    lb = int(info[0])
    ub = int(info[1])
    count = 0
    for n in range(lb,ub+1):
        if isFair(n) and isSquare(n):
            count+=1
    print "Case #%d: %d"% (test, count)
sys.exit(0)
