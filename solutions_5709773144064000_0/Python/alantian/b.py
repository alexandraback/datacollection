#!/usr/bin/env python3

import math

def rl(T=str):
    return [ T(_) for _ in input().split() ]

def solve( C, F, X ):
#    print( 'go for', C, F, X )

    if C >= X:
        return X / 2

    k = X / C - 2/F - 1
    k = math.floor( k + 1e-15 )
    k = k + 1
    k = max( k, 0.0 )
    k = int(k)

    answer = sum( C / (2+i*F) for i in range(k) ) + X / ( 2 + k*F )

#    print('k =',k,'answer = ',answer)

    return answer

T, *_ = rl(int)
for Case in range(1,T+1):
    C, F, X = rl(float)
    answer = solve(C, F, X)
    print('Case #%d: %.7f'%(Case,answer))

