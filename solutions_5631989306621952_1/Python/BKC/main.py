for tc in xrange(input()):
    s = list(raw_input())
    ans = []
    for i in xrange(len(s)):
        c = s.pop(0)
        if len(ans) and ord(c) >= ord(ans[0]):
            ans = [c] + ans
        else:
            ans = ans + [c]
    ans = ''.join(ans)
    print "Case #%d: %s" % (tc+1, ans)
