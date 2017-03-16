t = int(raw_input())

for i_ in xrange(t):
    b, m = map(int, raw_input().split())
    if m > 2 ** (b - 2):
        print 'Case #{}: IMPOSSIBLE'.format(i_ + 1)
    else:
        a = [[0] * b for _ in xrange(b)]
        for i in xrange(b):
            for j in xrange(i + 1, b - 1):
                a[i][j] = 1

        curr = 2 ** (b - 2)
        for i in xrange(b - 2, -1, -1):
            if curr - 2 ** (i - 1) >= m:
                curr -= 2 ** (i - 1)
            else:
                a[i][b - 1] = 1

        print 'Case #{}: POSSIBLE'.format(i_ + 1)
        for line in a:
            print ''.join(map(str, line))