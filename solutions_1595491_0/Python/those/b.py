ca = int(raw_input())
for t in range(1,ca+1):
    line = raw_input().split()
    n, s, p  = map(int,line[:3])
    a = sorted(map(int,line[3:]), reverse=True)
    ans = 0
    for k in a:
        if k >= p * 3 - 2:
            ans += 1
        elif (s > 0) and (k >= p):
            if p+(p-2)*2 <= k:
                ans += 1
                s -= 1
    print 'Case #%d: %d' % (t, ans)
