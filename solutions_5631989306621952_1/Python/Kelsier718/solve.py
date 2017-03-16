
t = int(input())
for i in range(1, t + 1):
    s = list(input())
    res = s[0]
    for j in range(1, len(s)):
        if res[0] <= s[j]:
            res = s[j] + res
        else:
            res = res + s[j]
        #print(res)
    print("Case #{}: {}".format(i, res))
