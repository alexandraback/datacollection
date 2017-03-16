t = int(input())
for i in range(1, t + 1):
    ans = 0
    s = input()
    in_group = False
    for cur in s:
        if cur == '-':
            if not in_group:
                ans += 2
                in_group = True
        else:
            in_group = False
    if ans > 0 and s[0] == '-':
        ans -= 1
    print("Case #{}: {}".format(i, ans))

