
from copy import copy

def solve(state, N, P):
    if not N:
        return 1 if P in state else 0
    y = 0
    while (0, y) in state:
        y += 2
    return solve2(state, N, (0, y), P)

def solve2(state, N, p, P):
    x, y = p
    while y > 0:
        l, r = (x - 1, y - 1) in state, (x + 1, y - 1) in state
        if l and r: break
        if l and not r: x += 1; y -= 1; continue
        if r and not l: x -= 1; y -= 1; continue
        return 0.5 * solve2(copy(state), N, (x - 1, y - 1), P) + \
               0.5 * solve2(copy(state), N, (x + 1, y - 1), P)
    state.add((x, y))
    return solve(state, N - 1, P)

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        N, X, Y = map(int, f.readline().split(' '))
        print 'Case #%d: %s' % (i + 1, solve(set(), N, (X, Y)))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
