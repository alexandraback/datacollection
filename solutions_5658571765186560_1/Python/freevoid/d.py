import sys

RICHARD = 'RICHARD'
GABRIEL = 'GABRIEL'

def solve(X, R, C):
    if R*C % X != 0:
        return RICHARD

    # pick a tile with a hole
    if X >= 7:
        return RICHARD

    if R > C:
        R, C = C, R

    assert R <= C

    # pick a longest tile - cannot fit
    if X > C:
        return RICHARD

    # pick a "fat" tile
    if (X // 2 + X % 2) > R:
        return RICHARD

    if X <= 3:
        return GABRIEL

    assert X > 3

    # pick a "T" shape - will divide sides into odd number of squares
    if X == 4:
        if R == 2:
            return RICHARD

    if (X, R, C) == (5, 3, 5):
        return RICHARD

    if X == 6 and R == 3:
        return RICHARD

    return GABRIEL

def read_ints():
    return map(int, sys.stdin.readline().split(' '))


if __name__ == '__main__':
    t, = read_ints()
    for i in range(t):
        X, R, C = read_ints()
        print 'Case #%d: %s' % (i + 1, solve(X, R, C))
