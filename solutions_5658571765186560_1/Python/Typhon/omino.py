richard = 'RICHARD'
gabriel = 'GABRIEL'
import sys

def solve(X, R, C):
    # for X > 6, Richard can just pick a Xomino with a hole in it. 
    if X > 6: return richard
    # trivial cases
    if R < 1 or C < 1: return richard
    if R < X and C < X: return richard # I block
    if (R*C) % X: return richard
    if X <= 2: return gabriel
    if X == 3:
        if (R == 1 or C == 1): return richard
        return gabriel
    if X == 4:
        if R <= 2 or C <= 2: return richard # T block or S block
        return gabriel
    if X == 5:
        if R <= 2 or C <= 2: return richard
        if R * C == 15: return richard # w block
        return gabriel 
    if X == 6:
        if R <= 2 or C <= 2: return richard 
        if R == 3 or C == 3: return richard # T block
        return gabriel

for i in range(1, int(raw_input()) + 1):
    X, R, C = map(int, raw_input().split())
    print 'Case #%d: %s' % (i, solve(X, R, C))
    sys.stdout.flush()
