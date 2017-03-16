dp = [0] * 1000001

def make_table():
    N = 1000000
    i = 1
    dp[1] = 1
    while i <= N:
        if i % 10 != 0 and int(str(i)[::-1]) < i - 1 and dp[int(str(i)[::-1])] < dp[i - 1]:
            dp[i] = dp[int(str(i)[::-1])] + 1
        else:
            dp[i] = dp[i - 1] + 1
        i += 1

def solve():
    N = int(raw_input())
    return dp[N]

T = int(raw_input())
make_table()
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
