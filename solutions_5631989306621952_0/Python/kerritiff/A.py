def solve(S):
    ans = S[0]
    for x in S[1:]:
        ans = max(x + ans, ans + x)
    return ans

t = int(input())

for i in range(t):
    x = input()
    print('Case #%d: %s' % (i + 1, solve(x)))
