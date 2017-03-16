#!/usr/bin/python

import sys, itertools, math

if __name__ == '__main__':
    cases = None
    for i, line in enumerate(sys.stdin):
        line = line.strip()

        if cases is None:
            cases = int(line)
            continue

        (X, R, C) = (int(a) for a in line.split())

        richard_wins = False
        if X >= 7:
            richard_wins = True

        if not richard_wins and (R * C) % X != 0:
            richard_wins = True

        if not richard_wins and X >= ((min(R, C) + 1) * 2 - 1):
            richard_wins = True

        if not richard_wins:
            if X == 1 or X == 2 or X == 3:
                richard_wins = False
            elif X == 4:
                richard_wins = min(R, C) == 2
            elif X == 5:
                richard_wins = min(R, C) == 3 and max(R, C) == 5
            elif X == 6:
                richard_wins = min(R, C) == 3

        print 'Case #%d: %s' % (i, 'RICHARD' if richard_wins else 'GABRIEL')
        sys.stdout.flush()
