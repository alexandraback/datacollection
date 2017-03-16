#!/usr/bin/python3

import sys

def rotates(n,B,log,msd):
    r = 0
    m = n
    ans = set()
    for i in range(0, log):
        d = m % 10
        m //= 10
        m += d * msd
        if n < m and m <= B and m not in ans:
            ans.add(m)
            r += 1
    return r
        
def log10(x):
    r = 0
    while x > 0:
        x //= 10
        r += 1
    return r

T=int(sys.stdin.readline())
for i in range(1,T+1):
    line=[int(x) for x in sys.stdin.readline().split()]
    A=line[0]
    B=line[1]
    log = log10(B) - 1
    msd = 10**(log)
    r = 0
    for j in range(A,B):
        r += rotates(j,B, log, msd)
    print("Case #%s: %s" %(i,r))
