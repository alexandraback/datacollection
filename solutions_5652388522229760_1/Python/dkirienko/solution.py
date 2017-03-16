def solve(test_num):
    n = int(input())
    if n == 0:
        ans = "INSOMNIA"
    else:
        s = set(str(n))
        n1 = n
        ans = 1
        while len(s) != 10:
            n1 += n
            s |= set(str(n1))
            ans += 1
        ans = str(n1)
    print("Case #", test_num, ": ", ans, sep="")

for i in range(1, int(input()) + 1):
    solve(i)

