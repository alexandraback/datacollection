#!/usr/bin/python3
import sys

f = open("C-small-attempt0.in")
g = open("C-small-attempt0.out", "w") # sys.stdout

def mkPal(x, odd=False):
     s = str(x)
     if odd:
        return s + s[-2::-1]
     return s + s[::-1]

def isPal(x):
    s = str(x)
    return s == s[::-1]

l = []

# precompute the list of all fair & square up to 10^14
for i in range(1, 10000):
    p = int(mkPal(i, odd=True))
    if isPal(p*p):
        l.append(p*p)
    p = int(mkPal(i))
    if isPal(p*p):
        l.append(p*p)

T = int(f.readline())
for caseNo in range(1, T+1):
    A, B = map(int, f.readline().strip().split())
    ans = len([x for x in l if A <= x <= B])
    print("Case #{0}: {1}".format(caseNo, ans), file=g)

g.close()
