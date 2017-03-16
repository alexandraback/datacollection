
T = int(input())
for t in xrange(T):
    cs = 'Case #' + str(t + 1) + ':'
    a, b, k = map(int, raw_input().split())
    ans = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                ans += 1
    print cs, ans
