def solve():
    S = raw_input()
    ans = S[0]
    for ch in S[1:]:
        if ans[0] <= ch:
            ans = ch + ans
        else:
            ans = ans + ch
    return ans

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
