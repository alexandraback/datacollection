from collections import defaultdict

def solve(N, A):
    Q = defaultdict(int)
    R = defaultdict(list)
    for i, a in enumerate(A):
        Q[i + 1] = a
        R[a].append(i + 1)

    pairs = set()
    circles = []
    for i in range(1, N+1):
        visited = defaultdict(bool)
        c = i
        while not visited[c]:
            visited[c] = True
            c = Q[c]

        q = [c]
        cc = Q[c]
        while cc != c:
            q.append(cc)
            cc = Q[cc]

        if len(q) == 2:
            pairs.add(tuple(sorted(q)))
        else:
            circles.append(q)

    def f(c, e, d):
        v = [f(j, e, d + 1) for j in R[c] if j != e]
        if len(v) == 0:
            return d
        return max(v)

    ans = 0
    for p in pairs:
        ans += 2 + f(p[0], p[1], 0) + f(p[1], p[0], 0)

    max_circle = 0
    if circles:
        max_circle = max([len(c) for c in circles])
    return max(ans, max_circle)

import sys
sys.stdin = open('C-large.in', 'rt')
sys.stdout = open('C-large.out', 'wt')

T = int(raw_input().strip())
for t in range(1, T+1):
    N = int(raw_input().strip())
    A = map(int, raw_input().strip().split(' '))
    print 'Case #{}:'.format(t), solve(N, A)
