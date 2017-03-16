for test in range(input()):
    input()
    P = map(int, raw_input().split())
    ans = max(P)
    for i in range(1, max(P)+1):
        ans = min(ans, i+sum((p+i-1)/i-1 for p in P))
    print "Case #%s: %s"%(test+1, ans)
