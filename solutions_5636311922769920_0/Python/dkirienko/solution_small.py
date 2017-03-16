def solve(test_num):
    k, c, s = map(int, input().split())
    print("Case #" + str(test_num) + ":", *[i + 1 for i in range(k)])

for i in range(1, int(input()) + 1):
    solve(i)

