t = int(input())
for ti in range(1, t + 1):
    data = [int(k) for k in input().split(' ')]
    b = data[0]
    m = data[1]
    if m > (1 << (b - 2)):
        print('Case #{}: IMPOSSIBLE'.format(ti))
    else:
        print('Case #{}: POSSIBLE'.format(ti))
        ans = [['0' for x in range(b)] for y in range(b)]
        for bi in range(b - 1):
            for bj in range(bi + 1, b - 1):
                ans[bi][bj] = '1'
        for bi in range(b - 2, 0, -1):
            if m >= (1 << (bi - 1)):
                m -= (1 << (bi - 1))
                ans[bi][b - 1] = '1'
        if m > 0:
            ans[0][b - 1] = '1'
        for x in ans:
            print(''.join(x))
