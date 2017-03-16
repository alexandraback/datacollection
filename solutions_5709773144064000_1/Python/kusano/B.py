for test in range(input()):
    C,F,X = map(float, raw_input().split())
    ans = X/2.
    t = 0
    c = 0
    while True:
        a = t + C/(2+c*F) + X/(2+(c+1)*F)
        if a>ans:
            break
        ans = a
        t += C/(2+c*F)
        c += 1
    print "Case #%s: %.10f" % (test+1, ans)
