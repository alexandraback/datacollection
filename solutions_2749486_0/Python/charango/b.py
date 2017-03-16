
def solve(X, Y):
    res = ''
    for i in xrange(abs(X)):
        res += 'WE' if X > 0 else 'EW'
    for i in xrange(abs(Y)):
        res += 'SN' if Y > 0 else 'NS'
    return res

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        X, Y = map(int, f.readline().split(' '))
        print 'Case #%d: %s' % (i + 1, solve(X, Y))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
