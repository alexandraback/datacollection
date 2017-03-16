#!/usr/bin/python3

import sys

def fact(x):
    res = 1
    while x > 1:
        res *= x;
        x -= 1;
    return res;

def c(n, k):
    return fact(n)//(fact(k)*fact(n-k))



def case():
    N, X, Y = [int(x) for x in sys.stdin.readline().split()]
    if X < 0: X *= -1
    if X+Y == 0: return 1.0
    side = X+Y-1
    fill = (side*(side + 1))/2
    if fill >= N: return 0.0
    remain = N - fill
    side = X+Y + 1
    fill = (side*(side + 1))/2
    if fill <= N: return 1.0
    if fill > N and X == 0: return 0.0

    if side - 1 + Y + 1 <= remain: return 1.0
    if remain < Y+1: return 0.0

    
    minpos = max(0, remain - (side -1))
    maxpos = min(side-1, remain)

    casesok = 0
    for i in range(Y+1, maxpos+1):
        casesok += c(remain, i)
    
    cases = 0
    for i in range(minpos, maxpos+1):
        cases += c(remain, i)
    #print([casesok, cases])


    #currc = c(remain, minpos)
    ##currc = float(currc)
    #cases = currc

    #for i in range(minpos+1, Y+1):
    #    currc *= (remain - i+1)
    #    currc /= i
    #    cases += currc
    #casesok = 0
    #for i in range(Y+1, maxpos+1):
    #    currc *= (remain - i+1)
    #    currc /= i
    #    casesok += currc
    #cases += casesok 
    ##print([casesok, cases])

    return float(casesok)/(cases)



    return float(casesok)/(cases)

T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case()))
    

