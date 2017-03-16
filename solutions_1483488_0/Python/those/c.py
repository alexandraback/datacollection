ca = int(raw_input())
for t in range(1,ca+1):
    line = map(int, raw_input().split())
    A, B = line
    ans = 0
    for x in range(A,B):
        s = str(x)
        while True:
            s = s[1:] + s[0]
            y = int(s)
            if x < y <= B:
                ans += 1
            if y == x:
                break
    print 'Case #%d: %d' % (t, ans)
