for t in range(input()):
    S = raw_input()
    ans = S.count("+-")*2 + int(S[0]=="-")
    print "Case #%s: %s" % (t+1, ans)
