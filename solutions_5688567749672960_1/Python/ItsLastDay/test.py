from random import randint

dp = [1005000 for i in range(10 ** 6 + 123)]
prev = [1005000 for i in range(10 ** 6 + 123)]

def solve(cnt=False, nn=1):
    if cnt:

        n = nn
        dp[1] = 1
        for i in range(1, n):
            ri = int(str(i)[::-1])
            if i < ri <= n:
                if dp[ri] > dp[i] + 1:
                    prev[ri] = i
                dp[ri] = min(dp[ri], dp[i] + 1)
            if dp[i + 1] > dp[i] + 1:
                prev[i + 1] = i
            dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    else:
        n = int(input())



    return dp[n]

def greedy(n, vb=False):
    mv = 1

    cur = 1

    while cur != n:
        ri = int(str(cur)[::-1])
        if cur < ri <= n:
            cur = ri
        else:
            cur += 1
    
        if vb:
            print(cur, end=' ')
        mv += 1

    return mv
        
def get_mn(sz):
    if sz == 1:
        return 1
    free = (sz + 1) // 2

    ans = 10 ** 100
    for f in range(1, 3):
        cur = int(str(f) + '0' * (free - 1) + '0' * (sz - free - 1) + '1')
        if int(str(cur)[::-1]) < cur:
            ans = min(ans, cur)

        if free > 1:
            for pos in range(1, free):
                cur = int(str(f) + '0' * (pos - 1) + '1' + '0' * (free - 2 - (pos - 1)) + '0' * (sz - free - 1) + '1')
                if int(str(cur)[::-1]) < cur:
                    ans = min(ans, cur)

    return ans



def ts(n):
    if n == 1:
        return 1

    sz = len(str(n))
    if sz == 1:
        return n

    if n < get_mn(sz):
        to = int('9' * (sz - 1))
        return n - to + ts(to)

    free = (sz + 1) // 2

    fi = int(str(n)[:free])
    se = int(str(n)[free:])

    if se == 0:
        fi -= 1

    nx = str(fi) + '0' * (sz - free - 1) + '1'
    nx = int(nx)

    return 1 + n - nx + ts(int(str(nx)[::-1]))



for t in range(1, int(input()) + 1):
    n = int(input())
    print('Case #%d: %d' % (t, ts(n)))
