def solve():
    S = raw_input()
    ans = [S[0]]
    for c in S[1:]:
        if c >= ans[0]:
            ans = [c] + ans
        else:
            ans.append(c)
    return ''.join(ans)

T = input()
for i in range(1, T+1):
    ans = solve()
    print('Case #%d: %s' % (i, ans))
 
