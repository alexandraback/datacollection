# coding: utf-8

import sys

def solve(X, R, C):
    if (R * C) < X:
        return 'RICHARD'
    if (R * C) % X != 0:
        return 'RICHARD'
    if min(R, C) < ((X + 1) // 2):
        return 'RICHARD'
    if X >= 7:
        return 'RICHARD'
    if R + C - 1 <= X and min(R, C) > 1:
        return 'RICHARD'
    if 2 * min(R, C) <= X and min(R, C) > 1:
        return 'RICHARD'
    return 'GABRIEL'

def main(fp):
    T = int(fp.readline())
    for t in range(T):
        X, R, C = tuple(map(int, fp.readline().strip().split(' ')))
        result = solve(X, R, C)
        print 'Case #{}: {}'.format(t + 1, result)

if __name__ == '__main__':
    if len(sys.argv) == 1:
        main(sys.stdin)
    elif len(sys.argv) == 2:
        with open(sys.argv[1]) as f:
            main(f)
    else:
        print >> sys.stderr, "Usage: python {} INPUT_FILE".format(sys.argv[0])
        sys.exit(1)
