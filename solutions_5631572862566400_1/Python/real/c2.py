import sys, itertools
from collections import defaultdict
sys.setrecursionlimit(100000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input


def trace_path(fr, memo):
    if fr in memo:
        return memo[fr]

    ans = 1
    for x in b[fr]:
        ans = max(ans, 1 + trace_path(x, memo))

    memo[fr] = ans
    return ans


T = read_int()
for ca in range(1, T + 1):
    n = read_int()
    e = [None] + read_ints()

    b = [[] for _ in xrange(n + 1)]

    for fr in xrange(1, n + 1):
        b[e[fr]].append(fr)

    ans = 0

    # Cycle
    memo = {}

    for i in xrange(1, n + 1):
        v = [False] * (n + 1)

        c = 1
        v[i] = True
        x = e[i]
        gg = [i]
        while not v[x]:
            gg.append(x)
            v[x] = True
            x = e[x]
            c += 1

        if x == i:
            ans = max(ans, c)

    # Two...
    others = 0
    for i in xrange(1, n + 1):
        for j in xrange(i + 1, n + 1):
            if e[i] == j and e[j] == i:
                memo = {i: 0, j: 0}
                c = 2 + \
                    max(trace_path(x, memo) for x in b[i]) + \
                    max(trace_path(x, memo) for x in b[j])
                others += c

    # WA1
    ans = max(ans, others)

    print 'Case #%d: %s' % (ca, ans)
