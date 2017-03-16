for c in xrange(input()):
    ans, up = 0, 0
    for i, x in enumerate(map(int, raw_input().split()[1])):
        if i > up: ans, up = ans + i - up, i
        up += x
    print "Case #" + str(c + 1) + ": " + str(ans)
