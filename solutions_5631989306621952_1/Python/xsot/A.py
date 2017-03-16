for t in range(1, int(input())+1):
    s = raw_input()
    lw = s[0]
    for c in s[1:]:
        if c >= lw[0]:
            lw = c + lw
        else:
            lw += c
    print "Case #%d: "%t + lw