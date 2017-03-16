# coding: utf-8

import sys
import math
import decimal

def solve(E, R, N, V):
    result = 0

    jouls = [None] * N
    look_around = (E - 1) / R + 1
    for index, value in sorted(enumerate(V), key=lambda x: x[1], reverse=True):

        r1 = 0
        for d in range(look_around):
            look_at = index - d - 1

            if look_at < 0:
                r1 = E
                break

            if not jouls[look_at]:
                r1 += R
                r1 = min(r1, E)
                continue

            r1 += R
            r1 = min(r1, E)
            break

        r2 = 0
        for d in range(look_around):
            look_at = index + d + 1

            if N <= look_at:
                r2 = r1
                break

            if not jouls[look_at]:
                r2 += R
                continue

            r2 += R
            r2 = min(r2, r1)
            if r2 <= jouls[look_at]:
                r2 = r1 - (jouls[look_at] - r2)
            break

        jouls[index] = max(min(r1, r2), 0)
        result += jouls[index] * value

    return result

if __name__ == '__main__':
    with open(sys.argv[1]) as f:
        lines = list(reversed(f.read().split('\n')))
        T = int(lines.pop())
        for case in range(T):
            E, R, N = map(int, lines.pop().split())
            V = map(int, lines.pop().split())
            result = solve(E, R, N, V)
            print 'Case #{}: {}'.format(case + 1, result)

