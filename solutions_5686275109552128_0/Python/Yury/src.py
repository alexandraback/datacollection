#!/usr/bin/python3

import sys
from itertools import *
#from functools import *
from pprint import pprint

def esim(PP, T):
    assert any(p >= T for p in PP)
    m = T + sum((max(p - T, 0)-1)//T + 1 for p in PP)
    return m

def solve(PP):
    L = max(PP)
    R = 1 # min(PP) #+1
    #if L == R:
    #    return L
    #vL = esim(PP, L)
    #vR = esim(PP, R)
    #while True:
    #    M1 = (2*L+R)//3
    #    M2 = (L+R*2)//3
    #    if L == M1 or M1 == M2 or M2 == R:
    #        break
    #    vM1 = esim(PP,M1)
    #    vM2 = esim(PP,M2)
    #    if vM1 > vM2:
    #        L = M1
    #    elif vM1 <= vM2:
    #        R = M2
    return min(esim(PP, p) for p in range(R, L+1))

def parse(ist):
    D = int(ist.readline().strip())
    PP = [int(i) for i in ist.readline().split()]
    assert len(PP) == D
    return PP

def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        res = solve(parse(sys.stdin))
        print('Case #{}: {}'.format(i+1, res))

def err(*m):
    print(*m, file=sys.stderr)

def perr(*m):
    pprint(m, stream=sys.stderr)

if __name__ == '__main__':
    sys.exit(main())
