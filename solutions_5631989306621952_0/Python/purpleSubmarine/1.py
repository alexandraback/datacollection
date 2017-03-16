t = int(raw_input())

for p in xrange(1, t + 1):
    s = raw_input()
    ans = ""
    for letter in s:
        if (ans == ""):
            ans += letter
        else:
            i = 0
            while (i < len(ans)) and (ans[i] == letter):
                i += 1
            if (i < len(ans)) and (ans[i] < letter):
                ans = letter + ans
            else:
                ans += letter
    print "Case #" + str(p) + ": " + ans
