touch = [[0] * 21 for i in xrange(21)]
find = [[0] * 21 for i in xrange(21)]
for c in xrange(1, 21):
    for w in xrange(1, c + 1):
        cnt = c / w
        touch[c][w] = cnt
        cnt += w - 1
        if c % w != 0:
            cnt += 1
        find[c][w] = cnt
        
T = int(raw_input())        
for case in xrange(1, T + 1):
    R, C, W = map(int, raw_input().split())
    ans = (R - 1) * touch[C][W] + find[C][W]
    print "Case #%d: %d" % (case, ans)
