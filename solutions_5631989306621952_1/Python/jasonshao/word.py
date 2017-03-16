t = input()
for poo in range(t):
    s = raw_input()
    ans = s[0]
    for i in s[1:]:
        if i < ans[0]:
            ans += i
        else:
            ans = i + ans
    print "Case #" + str(poo + 1) + ": " + ans
