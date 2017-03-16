def solve(test_num):
    n, A = input().split()
    n = int(n)
    A = list(map(int, list(A)))
    ans = 0
    curr_stand = A[0]
    for i in range(1, n + 1):
        if curr_stand < i:
            ans += i - curr_stand
            curr_stand = i
        curr_stand += A[i]
    print("Case #", test_num, ": ", ans, sep="")

for i in range(1, int(input()) + 1):
    solve(i)

