
def fits(x, s, fmt):
    x = fmt.format(x)
    for i in xrange(len(s)):
        if s[i] != '?' and s[i] != x[i]:
            return False
    return True

def f(a, b):
    fmt =  '{:0' + str(len(a)) + '}'
    best = (100000, 0, 0)
    for x in xrange(10**len(a)):
        if fits(x, a, fmt):
            for y in xrange(10**len(b)):
                if fits(y, b, fmt):
                    delta = abs(x - y)
                    if (delta, x, y) < best:
                        best = (delta, x, y)

    return fmt.format(best[1]), fmt.format(best[2])

test_count = int(raw_input().strip())
for test in xrange(1, test_count + 1):
    s = raw_input().strip()
    a, b = s.split(' ')
    a, b = f(a, b)
    print 'Case #{}: {} {}'.format(test, a, b)
