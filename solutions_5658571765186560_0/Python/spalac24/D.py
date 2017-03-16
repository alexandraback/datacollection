import sys
import math
import os


def nex(t=int):
    return t(sys.stdin.readline().strip())


def solve(x, r, c):

    # Hole in the middle
    if x > 6:
        return 'RICHARD1'

    # Cannot possibly fill
    if (r*c) % x:
        return 'RICHARD2'

    # Pick a large enough L shape
    if 2 * min(r, c) < x:
        return 'RICHARD3'

    if max(r, c) < x:
        return 'RICHARD8'

    if x == 1:
        return 'GABRIEL4'

    if x == 2:
        return 'GABRIEL5'

    if x == 3:
        return 'GABRIEL6'

    if x == 4:
        if min(r, c) == 2:
            return 'RICHARD10'
        return 'GABRIEL9'



    return 'GABRIEL7'


def main():
    t = nex()
    for case in range(1, t + 1):
        ans = None
        x, r, c = [int(t) for t in sys.stdin.readline().split()]
        ans = solve(x, r, c)[:7]
        sys.stdout.write('Case #%s: %s\n' % (case, ans))


if __name__ == '__main__':
    main()
