for iter_num in range(1, int(input()) + 1):
    r, c, w = map(int, input().split())
    res = c // w + w
    if c % w == 0:
        res -= 1
    res *= r
    print("Case #" + str(iter_num) + ": " + str(res))
