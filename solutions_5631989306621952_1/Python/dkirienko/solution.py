def solve(test_num):
    s = input()
    ans = ""
    for c in s:
        ans = max(c + ans, ans + c)
    print("Case #", test_num, ": ", ans, sep="")

for i in range(1, int(input()) + 1):
    solve(i)

