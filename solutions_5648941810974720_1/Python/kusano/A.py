for t in range(input()):
    S = raw_input()
    c = [0]*10
    c[0] = S.count("Z")
    c[2] = S.count("W")
    c[4] = S.count("U")
    c[6] = S.count("X")
    c[8] = S.count("G")
    c[3] = S.count("R") - c[0] - c[4]
    c[5] = S.count("F") - c[4]
    c[7] = S.count("S") - c[6]
    c[9] = S.count("I") - c[5] - c[6] - c[8]
    c[1] = S.count("N") - c[7] - 2*c[9]
    ans = "".join(str(i)*c[i] for i in range(10))
    print "Case #%s: %s" % (t+1, ans)
