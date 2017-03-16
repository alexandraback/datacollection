#!/usr/bin/env python

import sys


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    
    for i in range(T):
        X, R, C = list(map(int, sys.stdin.readline().split()))
        R, C = min(R, C), max(R, C)

        # Richard can win if:
        #  - X is larger than 6 (in which case an omino with an inaccessible block)
        #  - The number of squares in the grid is not divisible by X
        #  - X is larger than R and C
        #  - X is more than twice as large as the smaller dimension
        if X > 6 or R * C % X > 0 or X > C or X > 2 * R:
            print('Case #%d: RICHARD' % (i + 1))

        # Gabriel can always win if X is less than 3
        elif X < 3:
            print('Case #%d: GABRIEL' % (i + 1))

        # Gabriel can win for higher X = 3, 4, 5, 6 with restrictions on the dimensions
        elif X == 3 and R >= 2 and (R % 3 == 0 or C % 3 == 0):
            print('Case #%d: GABRIEL' % (i + 1))

        elif X == 4 and R >= 3:
            print('Case #%d: GABRIEL' % (i + 1))

        # Otherwise, Richard wins
        else:
            print('Case #%d: RICHARD' % (i + 1))