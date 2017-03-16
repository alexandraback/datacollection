t = int(raw_input())

for i in xrange(1, t + 1):
    s = raw_input()

    ans = [s[0]]
    for j in range(1, len(s)):
        if s[j] >= ans[0]:
            ans.insert(0, s[j])
        else:
            ans.append(s[j])
    print "Case #{}: {}".format(i, "".join(ans))

