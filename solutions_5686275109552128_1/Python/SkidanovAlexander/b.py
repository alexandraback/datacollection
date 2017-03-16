for t in range(int(raw_input())):
    n = int(raw_input())
    a = [int(x) for x in raw_input().split()]
    a = sorted(a)
    ans = a[-1]
    for i in range(1, 1000):
        moves = 0
        for v in a:
            moves += (v - 1) / i
        if moves + i < ans:
            ans = moves + i
    print "Case #%d: %d" % (t + 1, ans)

