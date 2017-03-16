
def solve(A, m):
    alt = 0
    for mote in sorted(m):
        if A > mote: A += mote; continue
        if mote == 1: alt += 1; continue
        if 2 * A - 1 > mote:
            A += A - 1
        alt += 1
    return alt

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        A, N = map(int, f.readline().split(' '))
        m = map(int, f.readline().split())
        print 'Case #%d: %d' % (i + 1, solve(A, m))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
