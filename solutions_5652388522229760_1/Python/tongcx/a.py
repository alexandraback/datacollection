from sys import stdin

T = int(stdin.readline())
for case in range(1, T+1):
    N = int(stdin.readline())
    if N == 0:
        ans = 'INSOMNIA'
    else:
        seen = set()
        n = 0
        while True:
            n += N
            seen |= set(str(n))
            if len(seen) == 10:
                ans = n
                break
    print 'Case #{}: {}'.format(case, ans)
