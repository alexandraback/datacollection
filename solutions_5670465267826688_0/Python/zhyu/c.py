matrix = [
    [0, 1, 2, 3],
    [1, 4, 3, 6],
    [2, 7, 4, 1],
    [3, 2, 5, 4],
]


def multiply(x, y):
    flag = 0
    if x > 3:
        x -= 4
        flag ^= 1
    if y > 3:
        y -= 4
        flag ^= 1
    res = matrix[x][y]
    if not flag:
        return res
    return res-4 if res > 3 else res+4


def solve(l, x):
    if x > 12:
        x = (x % 4) + 12
    l *= x
    s = map(lambda ch: ord(ch)-ord('i')+1, raw_input() * x)
    dp = [s[0]] + [0] * (l-1)
    for i in xrange(1, l):
        dp[i] = multiply(dp[i-1], s[i])
    if dp[-1] != 4:
        return 'NO'
    for i in xrange(l):
        for j in xrange(i+2, l):
            if dp[i] == 1 and dp[j-1] == 3:
                return 'YES'
    return 'NO'

t = int(raw_input())
for cas in xrange(t):
    l, x = map(int, raw_input().split())
    print 'Case #{0}: {1}'.format(cas+1, solve(l, x))
