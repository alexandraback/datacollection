
def S(r, n):
    return n*(2*r+2*n-1)


T = int(raw_input())
for no in range(T):
    r, t = [int(s) for s in raw_input().split()]
    ans = 0
    for i in range(64):
        v = 1 << (63 - i)
        if S(r, ans+v) <= t:
            ans += v
    print 'Case #{0}: {1}'.format(no+1, ans)

