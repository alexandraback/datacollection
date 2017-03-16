for c in xrange(int(raw_input())):
    s = raw_input()

    ans = s[0]
    for ch in s[1:]:
        if ans[0] <= ch:
            ans = ch + ans
        else:
            ans += ch

    print "Case #%d:"%(c+1), ans
