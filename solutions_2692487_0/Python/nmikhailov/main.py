#!/usr/bin/env python3

def calc():
    cur, n = list(map(int, input().split(" ")))
    vals = list(map(int, input().split(" ")))

    vals.sort()

    dp = [[None] * (n + 1) for y in range(n + 1)]
    dp[0][0] = cur
    def upd(i, j, val):
        if not dp[i][j]:
            dp[i][j] = val
            return
        if dp[i][j] < val:
            dp[i][j] = val


    for i in range(0, n):
        for j in range(0, n):
            cur = dp[i][j]
            if not cur:
                continue

            upd(i + 1, j + 1, cur)

            cnt = 0
            while cur <= vals[i]:
                cur += cur - 1
                cnt += 1
                if cur - 1 <= 0:
                    cnt = 1000000
                    break

            if cnt + j <= n:
                upd(i + 1, j + cnt, cur + vals[i])

    for i in range(0, n):
        if dp[n][i]:
            return i
    return n


if __name__ == '__main__':
    cnt = int(input())
    for T in range(cnt):
        print("Case #{}: {}".format(T + 1, calc()))

