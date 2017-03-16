for TC in range(1, int(raw_input()) + 1):
    a, b, k = map(int, raw_input().split())
    
    ans = 0
    for i in range(a):
        for j in range(b):
            if i&j < k:
                ans += 1
    
    print "Case #%d: %d" % (TC, ans)