def solve(test_num):
    s = input()
    ans = 0
    for i in range(1, len(s)):
        ans += (s[i - 1] != s[i])
    ans += (s[-1] == '-')
    print("Case #", test_num, ": ", ans, sep="")

for i in range(1, int(input()) + 1):
    solve(i)

