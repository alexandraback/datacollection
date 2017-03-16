#!/usr/bin/env python3

import math

def rl(T=str):
    return [ T(_) for _ in input().split() ]

def micro( R, C, M ):
    assert R <= 3
    assert C <= 3
    assert R <= C

    if R == 3 and C == 3:
        res = [ [ '.' for j in range(C) ]for i in range(R) ]
        res[0][0] = 'c'
        if M == 0:
            return res
        elif M == 1:
            res[2][2] = '*'
            return res
        elif M == 3:
            res[0][2] = res[1][2] = res[2][2] = '*'
            return res
        elif M == 5:
            res[0][2] = res[1][2] = res[2][2] = '*'
            res[2][0] = res[2][1] = '*'
            return res
        elif M == 8:
            res = [ [ '*' for j in range(C) ]for i in range(R) ]
            res[0][0] = 'c'
            return res
        else:
            return None
    elif R == 2 and C == 3:
        if M == 0:
            res = [ [ '.' for j in range(C) ]for i in range(R) ]
            res[0][0] = 'c'
            return res
        elif M == 2:
            return [ ['c','.','*'], ['.','.','*'] ]
        elif M == 5:
            return [ ['c','*','*'], ['*','*','*'] ]
        else:
            return None
    elif R == 2 and C == 2:
        if M == 0:
            return [ ['c','.'], ['.','.'] ]
        elif M == 3:
            return [ ['c','*'], ['*','*'] ]
        else:
            return None
    elif R == 1 and C == 3:
        if M == 0:
            return [ ['c','.','.'] ]
        elif M == 1:
            return [ ['c','.','*'] ]
        elif M == 2:
            return [ ['c','*','*'] ]
        else:
            return None
    elif R == 1 and C == 2:
        if M == 0:
            return [ ['c','.'] ]
        elif M == 1:
            return [ ['c','*'] ]
        else:
            return None
    elif R == 1 and C == 1:
        if M == 0:
            return [ ['c'] ]
        else:
            return None


def go( R, C, M ):

    if M >= C and R > 3:
        sub = solve( R-1, C, M-C )
        if not sub:
            return None
        return sub + [ ['*'] * C ]
    
    if M >= R and C > 3:
        sub = solve( R, C-1, M-R )
        if not sub:
            return None
        return [ row + ['*'] for row in sub ]

    
    if R <= 3 and C <= 3:
        return micro( R, C, M)
        
    else:

        res = [ [ '.' for j in range(C) ]for i in range(R) ]
        for c in range( C-1, 1, -1 ):
            if M == 0:
                break
            for r in range( R-1, 1, -1 ):
                if M == 0:
                    break
                M -= 1
                res[r][c] = '*'
        

        res[0][0] = 'c'
    
        if M == 0:
            return res
        else:
            return None

def solve( R, C, M ):
    if R > C:
        rev = True
        R, C = C, R
    else:
        rev = False
    
    res = go(R, C, M)

    if rev and res:
        res = [ [ res[j][i] for j in range(R) ] for i in range(C) ]

    return res

T, *_ = rl(int)
for Case in range(1,T+1):
    R, C, M = rl(int)
    answer = solve(R, C, M)
    print('Case #%d:'%(Case))
    
    if answer:
        for row in answer:
            print(''.join(row))
    else:
        print('Impossible')

