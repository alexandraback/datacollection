for t in range(input()):
    s = map(int, list(raw_input().split()[1]))
    ans = 0
    n = 0
    for i in range(len(s)):
        ans += max(i-n, 0)
        n += max(i-n, 0)
        n += s[i]
    print "Case #%d: %d"%(t+1, ans)
