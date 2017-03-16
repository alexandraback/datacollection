#!/usr/bin/python
import sys

T = int(sys.stdin.readline())

def calc(pos, ch, dp, str):
    while pos >= 0 and str[pos] == ch:
        pos -= 1

    if pos == -1:
        return 0
    if pos == 0:
        return 1
    return dp[pos - 1][1 if ch == '+' else 0] + 1

def solve(str):
    n = len(str)
    dp = [[-1, -1] for i in range(n)]
    for i in range(n):
        dp[i][0] = calc(i, '+', dp, str)
        dp[i][1] = calc(i, '-', dp, str)
    
    return dp[n - 1][0]

for testId in range(1, T + 1):
    str = sys.stdin.readline().strip()
    print 'Case #%s: %s' % (testId, solve(str))

