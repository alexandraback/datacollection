def solve(test_num):
    k, c, s = map(int, input().split())
    if s < k + 1 - c:
        print("Case #" + str(test_num) + ": IMPOSSIBLE")
        return
    ans = [i + 1 for i in range(k)]
    it = 0
    while len(ans) > s:
        for i in range(len(ans)):
            ans[i] += it * k ** it
        it += 1
        ans.pop(0)
    print("Case #" + str(test_num) + ":", *ans)

for i in range(1, int(input()) + 1):
    solve(i)

