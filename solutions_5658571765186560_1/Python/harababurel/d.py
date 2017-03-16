for t in range(0, input()):
    x, n, m = map(int, raw_input().split())

    ans = True
    if n < x and m < x: ans = False
    if x >= n + m - 1 and x > 2: ans = False
    if (n * m) % x != 0: ans = False
    if x >= 8: ans = False
    if n*m == 2*x and n*m==8: ans = False

    print "Case #%i: %s" % (t+1, ["RICHARD", "GABRIEL"][ans])
