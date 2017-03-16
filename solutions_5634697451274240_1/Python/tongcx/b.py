from sys import stdin

T = int(stdin.readline())

for case in xrange(1, T+1):
    S = stdin.readline().strip()
    ans = 0
    for x, y in zip(S[:-1], S[1:]):
        if x != y:
            ans += 1
    if S[-1] == '-': ans += 1
    print 'Case #{}: {}'.format(case, ans)
