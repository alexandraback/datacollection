# coding: utf-8

memo = []

def solve(E, R, N, V, maxE):
    if not V: return 0
    if memo[len(V) - 1][E] >= 0:
        return memo[len(V) - 1][E]
    res = 0
    for i in xrange(E + 1):
        t = solve(min(maxE, E - i + R), R, N, V[1:], maxE) + i * V[0]
        res = max(res, t)
    memo[len(V) - 1][E] = res
    return res

def main():
    TC = int(raw_input())
    for tc in xrange(1, TC + 1):
        E, R, N = map(int, raw_input().split())
        memo = [[-1] * E for i in xrange(N)]
        V = map(int, raw_input().split())
        print 'Case #%d: %d' % (tc, solve(E, R, N, V, E))

if __name__ == '__main__':
    main()
