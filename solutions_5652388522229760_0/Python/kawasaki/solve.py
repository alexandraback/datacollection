T = int(raw_input())
for t in xrange(1, T + 1):
    N = int(raw_input())
    if N == 0:
        print 'Case #{}: INSOMNIA'.format(t)
    else:
        i, s = 1, set()
        while len(s) < 10:
            s |= set(str(N * i))
            i += 1
        print 'Case #{}: {}'.format(t, N * (i - 1))
