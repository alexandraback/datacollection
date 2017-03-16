testcase = int(raw_input())
for caseno in range(1, testcase+1):
    r, t = map(int, raw_input().split())
    n = 1
    while t >= (r * 2 + 1) * n + n * (n-1) * 2:
        n *= 2
    fr = n / 2
    to = n
    while n != (fr + to) / 2:
        n = (fr + to) / 2
        total = (r * 2 + 1) * n + n * (n-1) * 2
        if t > total:
            fr = (fr + to) / 2
        elif t < total:
            to = (fr + to) / 2
        else:
            break
    while t < (r * 2 + 1) * n + n * (n-1) * 2:
        n -= 1
    print 'Case #%d: %d' % (caseno, n)
