t = int(raw_input())

for i in xrange(t):
    n = int(raw_input())

    seen = [0] * 10

    res = 'INSOMNIA'

    if (n != 0):
        for j in xrange(1, 73):
            num = j * n

            for l in str(num):
                seen[int(l)] = 1

            if (sum(seen) == 10):
                res = num
                break

    print 'Case #%d: %s' % (i + 1, str(res))