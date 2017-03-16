import sys
from collections import deque
rl = lambda: sys.stdin.readline().strip()

T = int(rl())
for tcase in range(1, T + 1):
    print >> sys.stderr, tcase
    N = int(rl())
    seen = set([1])
    Q = deque([(1, 1)])
    ans = 1
    while Q:
        c, n = Q.popleft()
        if c == N:
            ans = n
            break
        if c + 1 not in seen:
            seen.add(c + 1)
            Q.append((c + 1, n + 1))
        rc = int(str(c)[::-1])
        if rc not in seen:
            seen.add(rc)
            Q.append((rc, n + 1))
    print 'Case #%d: %d' % (tcase, ans)
