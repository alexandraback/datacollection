t = int(raw_input())
for i in xrange(1, t + 1):
    s = raw_input()
    ans = ""
    for j in s:
        if len(ans) == 0:
            ans += j
        elif ord(j) >= ord(ans[0]):
            ans = j + ans
        else:
            ans += j
    print "Case #{}: {}".format(i, ans)
