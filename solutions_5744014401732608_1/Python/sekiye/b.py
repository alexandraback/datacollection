from multiprocessing import Pool

def solve((B, M)):
    if M > 2 ** (B - 2):
        return 'IMPOSSIBLE'
    ans = 'POSSIBLE\n0'
    for i in xrange(1, B):
        cur = max(1, 2 ** (B - i - 2))
        if M >= cur:
            M -= cur
            ans += '1'
        else:
            ans += '0'
    ans = ans + '\n'
    for i in xrange(B - 1):
        for j in xrange(B):
            if i < j - 1:
                ans += '1'
            else:
                ans += '0'
        ans = ans + '\n'
    return ans[:-1]

T = int(raw_input())
p = Pool(4)
args = []
for i in range(T):
    B, M = map(int, raw_input().split())
    args.append((B, M))
ans = p.map(solve, args)
for i in range(T):
    print 'Case #%d:' % (i + 1), ans[i]
