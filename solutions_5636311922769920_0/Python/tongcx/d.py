from sys import stdin

T = int(stdin.readline())
for case in xrange(1, T+1):
    K, C, S = map(int, stdin.readline().split())
    ans = []
    tmp = 0
    cnt = 0
    for i in xrange(K):
        tmp = tmp * K + i
        cnt += 1
        if cnt == C:
            ans.append(tmp+1)
            tmp = 0
            cnt = 0
            S -= 1
    if cnt > 0:
        ans.append(tmp+1)
        S -= 1
    print 'Case #{}:'.format(case),
    if S >= 0:
        print ' '.join(map(str, ans))
    else:
        print 'IMPOSSIBLE'
