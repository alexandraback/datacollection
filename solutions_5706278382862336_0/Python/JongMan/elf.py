rl = raw_input

def solve(p, q):
    for i in xrange(1, 41):
        left = (2 ** 40) * p
        if left % q > 0: continue

        quot = left / q

        remainder = quot - 2 ** (40 - i)
        if 0 <= remainder <= ((2**i)-1) * (2 ** (40-i)):
            return i
    return -1


cases = int(rl())
for cc in xrange(cases):
    p, q = map(int, rl().strip().split('/'))

    g = solve(p, q)
    print 'Case #%d:' % (cc+1),
    if g == -1:
        print 'impossible'
    else:
        print g

