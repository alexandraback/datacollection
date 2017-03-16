n = input()

for i in xrange(n):
    s = raw_input()
    ans = ""
    for c in s:
        if len(ans) == 0 or c >= ans[0]:
            ans = c + ans
        else:
            ans = ans + c

    print "Case #" + str(i + 1) + ": " + ans