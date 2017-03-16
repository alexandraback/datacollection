T=int(input())
for case_id in range(1,T+1):
    N=int(input())
    def solve():
        n = N
        if n == 0:
            return 'INSOMNIA'
        s = set(c for c in str(n))
        while True:
            n += N
            s |= set(c for c in str(n))
            if len(s) == 10:
                return str(n)

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    import sys
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
