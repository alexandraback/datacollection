T = int(input())
D = 1
while (D<=T):
    s = input()
    f = s[0]
    ans = s[0]
    for c in s[1:]:
        ans = (ans + c) if c < ans[0] else (c + ans)
    print("Case #" + str(D) + ": " + ans)
    D += 1
