from collections import defaultdict

T = int(raw_input().strip())


for t in range(T):
    B,M = map(int,raw_input().strip().split(' '))
    if 2**(B-2) < M:
        print "Case #%d: %s" % (t+1, 'IMPOSSIBLE')
        continue
    vals = [0]*B
    paths = [[0 for x in xrange(B)] for y in xrange(B)]
    paths[0][B-1] = 1
    vals[B-1] = 1
    left = M - 1
    cur = B-2
    while left > 0:
        curneed = min(left, 2**(B-cur-2))
        paths[0][cur] = 1
        vals[cur] = curneed
        c2 = B-1
        #print left, curneed
        left -= curneed
        for x in xrange(cur+1, B):
            if curneed >= vals[x]:
                paths[cur][x] = 1
                curneed -= vals[x]
        cur -=1
    print "Case #%d: %s" % (t+1, 'POSSIBLE')
    for x in xrange(B):
        print ''.join(map(lambda y: str(y), paths[x]))