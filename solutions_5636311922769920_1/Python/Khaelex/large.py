import sys
from math import ceil

def solve_small(k, c):
    spots = [i * k**(c-1) for i in range(k)]
    return ' '.join(str(spot+1) for spot in spots)


def solve(k, c, s):
    if c == 1 or k == 1:
        if k == s:
            return solve_small(k, c)
        else:
            return 'IMPOSSIBLE'
    if s * c < k:
        return 'IMPOSSIBLE'

    spots = []
    e = min(k, c)
    for i in range(0, s * e, e):
        spot = 0
        for j in range(e-1,-1,-1):
            index = i + (e - j - 1)
            if index < k:
                spot += index * (k ** j)
        spots.append(min(spot, k ** c - 1))
    assert len(spots) <= s
    return ' '.join(str(spot + 1) for spot in spots)

if __name__ == '__main__':
    next(sys.stdin)
    case = 0
    for line in sys.stdin:
        case += 1
        k, c, s = [int(s) for s in line.strip().split(' ')]
        print('Case #{}: {}'.format(case, solve(k, c, s)))
