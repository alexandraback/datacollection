import math

def is_vowels(ch):
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'

def solve():
    s, n = raw_input().split()
    n = int(n)
    L = len(s)
    ans = 0
    for i in xrange(L + 1):
        for j in xrange(i):
            sub = s[j:i]
            count = 0
            for k in sub:
                if is_vowels(k):
                    count = 0
                else:
                    count += 1
                if count >= n:
                    ans += 1
                    break
    return ans
    # dp = [0] * (L + 1)
    # dp[0] = 1
    # ans = 0
    # for ch in s:
    #     if is_vowels(ch):
    #         tmp = 0
    #         for i in xrange(n):
    #             tmp += dp[i]
    #             dp[i] = 0
    #         dp[0] = tmp + 1
    #     else:
    #         for i in range(1, L)[::-1]:
    #             dp[i] = dp[i - 1]
    #         dp[0] = 1
    #     for i in xrange(n, L):
    #         ans += dp[i]
    # return ans

T = int(raw_input())
for i in xrange(T):
    print "Case #%d:" % (i + 1), solve()
