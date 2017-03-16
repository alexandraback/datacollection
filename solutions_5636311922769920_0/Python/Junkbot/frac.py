T = int(raw_input())

for z in xrange(1,T+1):
    K, C, S = map(int, raw_input().split())

    if S*C < K:
        ans = 'IMPOSSIBLE'
    else:
        ans = []
        cur = -1
        for i in xrange(K):
            if cur == -1:
                cur = 0
            cur *= K
            cur += i
            if (i+1) % C == 0:
                ans.append(cur+1)
                cur = -1
        if cur != -1:
            ans.append(cur+1)
        ans = ' '.join(map(str, ans))

    print 'Case #%d: %s' % (z, ans)
