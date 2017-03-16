from sys import stdin, stdout

stdin = open('B-small-attempt0.in', 'r')
stdout = open('B-small.out', 'w')

T = int(stdin.readline().strip())

for c in range(0, T):

    (E, R, N) = [int(x) for x in stdin.readline().strip().split()]

    v = [int(x) for x in stdin.readline().strip().split()]

    dp = [-1] * E + [0]

    ans = 0

    for k in range(N):
        dp2 = [-1] * (E + 1)
        for i in range(E+1):
            if dp[i] == -1:
                continue
            for j in range(i+1):
                val = v[k] * j + dp[i]
                jj = min(i-j+R, E)
                dp2[jj] = max(dp2[jj], val)
                ans = max(ans, dp2[jj])
        dp = dp2

    stdout.write('Case #%d: %d\n' % (c+1, ans))


stdin.close()
stdout.close()
