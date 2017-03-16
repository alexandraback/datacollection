T = int(input())
for z in range(T):
    print("Case #", z + 1, ": ", sep='', end='')
    k, c, s = map(int, input().split())
    if (s < (k + c - 1) // c):
        print("IMPOSSIBLE")
        continue
    kpows = [1] * (c + 1)
    for i in range(1, c + 1):
        kpows[i] = kpows[i - 1] * k
    curTile = 0
    for i in range(1, k + 1):
        curTile += (i - 1) * kpows[c - (i - 1) % c - 1]
        if (i % c == 0):
            print(curTile + 1, end=' ')
            curTile = 0
        # print(i, (i - 1) % c, kpows[(i - 1) % c])
    if (k % c):
        print(curTile + 1, end=' ')
    print()
