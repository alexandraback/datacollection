n = int(input())

for i in range(n):
    inp = input()
    ans = inp[0]
    for s in inp[1:]:
        if s >= ans[0]:
            ans = s + ans
        else:
            ans = ans + s
    print("Case #{}: {}".format(i+1, ans))
