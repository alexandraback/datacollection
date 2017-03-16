def solve():
    n = int(input())
    c = [0 for _ in range(2501)]
    for _ in range(2 * n - 1):
        a = map(int, input().split())
        for x in a:
            c[x] += 1
    res = []
    for i in range(2501):
        if c[i] % 2 == 1:
            res.append(i)
    res.sort()
    return ' '.join(str(x) for x in res)


t = int(input())
for tt in range(1, t + 1):
    print("Case #" + str(tt) + ":", solve())
