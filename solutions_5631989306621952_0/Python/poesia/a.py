T = int(input())

for tc in range(1, T+1):
    s = input()
    ans = s[0]

    for c in s[1:]:
        if c >= ans[0]:
            ans = c + ans
        else:
            ans += c
    print("Case #{}: {}".format(tc, ans))
