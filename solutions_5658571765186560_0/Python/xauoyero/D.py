#!/usr/bin/env python
# python 2.x
# 64

def sol(X, R, C):
    if X <= 0 or R <= 0 or C <= 0:
        print('Error')
        return False
    if (R*C) % X != 0:
        return False
    if X in [1, 2]:
        return True
    if R > C:
        R, C = C, R
    if X == 3:
        if R == 1:
            #L == 3, L fail
            return False
        else:
            return True
    if X == 4:
        if R in [1, 2]:
            return False
        else:
            return True
    print('Error: X=%s' % X)
    return False

T = int(raw_input())
for t in xrange(1, T + 1):
    FMT = "Case #%s: %s"
    # [1, 4]
    X, R, C = map(int, raw_input().split())
    if sol(X, R, C):
        print(FMT % (t, 'GABRIEL'))
    else:
        print(FMT % (t, 'RICHARD') )
