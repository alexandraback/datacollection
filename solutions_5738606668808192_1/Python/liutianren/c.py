#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

def isprime(n):
    t=3
    while t*t <= n:
        if n%t == 0:
            return t
        t += 2
    return 0

def tobits(n):
    x = n
    bits = []
    while x>0:
        bits.append(x&1)
        x = x >> 1;
    bits.reverse()
    return bits

def tonum(bits,K):
    n = 0
    for b in bits:
        n = K * n + b
    return n

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print("Case #{}:".format(t+1))
        N,J = map(int, sys.stdin.readline().split())
        if N>14:
            for n in range(2**(N-1)+1,2**N,2):
                if J<=0:
                    break
                bits = tobits(n)
                # for K in range(2,11):
                s = 0
                for b in bits:
                    s = -s-b
                if s==0:
                    print("".join(str(b) for b in bits), "3 4 5 6 7 8 9 10 11")
                    J = J-1
        else:
            for n in range(2**(N-1)+1,2**N,2):
                if J<=0:
                    break
                bits = tobits(n)
                d = []
                for K in range(2,11):
                    nK = tonum(bits,K)
                    dK = isprime(nK)
                    if dK == 0:
                        break
                    d.append(dK)
                else:
                    print("".join(str(b) for b in bits), " ".join(str(dK) for dK in d))
                    J = J-1
