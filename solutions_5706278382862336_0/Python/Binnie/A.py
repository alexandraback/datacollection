import sys
from fractions import *

def isPowerOfTwo(n):
    ii = 1
    while ii <= n:
        if ii == n:
            return True
        ii *= 2
    return False

def calcScore(fra):
    ii = 1
    target = Fraction(1,2)

    while True:
        if (fra >= target): return ii
        else:
            ii += 1
            target *= Fraction(1,2)

f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    P, Q = map(int, f.readline().strip().split("/"))
    fract = Fraction(P, Q)
    denom = fract.denominator
    possible = False
    if (isPowerOfTwo(denom)):
        possible = True
        score = calcScore(fract)


    print "Case #%d: " % (test + 1), score if possible else "impossible"



