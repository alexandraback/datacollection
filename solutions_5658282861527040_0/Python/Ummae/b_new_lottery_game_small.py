import sys
rl = lambda: sys.stdin.readline().strip()

T = int(rl())
for tcase in range(T):
    A, B, K = map(int, rl().split())
    all_num = []
    for a in range(A):
        for b in range(B):
            all_num.append(a & b)
    ans = 0
    for n in all_num:
        if n < K:
            ans += 1
    print 'Case #%d: %d' % (tcase + 1, ans)
