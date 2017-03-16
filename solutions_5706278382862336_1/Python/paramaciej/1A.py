#!/usr/bin/env python3
import fractions

def isPow(q):
    if q&1 == 0:
        return isPow(q>>1)
    elif q == 1:
        return True
    else:
        return False

T = int(input())

for t in range(1, T+1):
    P, Q = [int(x) for x in input().split('/')]
    P, Q = int(P/fractions.gcd(P,Q)), int(Q/fractions.gcd(P,Q))
    if isPow(Q):
        gen = 1
        anc = 2
        found = False
        while gen <= 40 and not found:
            if Q/anc <= P:
                found = True
            else:
                gen += 1
                anc <<= 1
        if found:
            print("Case #{}: {}".format(t, gen))
        else:
            print("Case #{}: impossible".format(t))
    else:
        print("Case #{}: impossible".format(t))
    
