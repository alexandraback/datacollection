import sys
from fractions import gcd

def getpow(Q):
    ret = 0
    while (Q>0):
        if (Q==1):
            return ret
        elif (Q%2 == 0):
            ret = ret + 1
            Q = Q /2
        else:
            return -1

def getpow1(P):
    ret = 0
    while (P>=2):
        ret = ret + 1
        P = P / 2
    return ret

def solve():
    ans = 0
    [P, Q] = map(int, sys.stdin.readline().strip().split('/'))
    g = gcd(P,Q)
    P = P / g
    Q = Q / g
#     print [P,Q]
    q = getpow(Q)
    if (q == -1):
        return "impossible"
    p = getpow1(P)
    ans = q - p
    return ans


T = int (sys.stdin.readline())

for case in range(1,T+1):
    print "Case #" + str(case) + ": " + str(solve())