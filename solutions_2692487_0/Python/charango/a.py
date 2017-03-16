
def check(A, t):
    res = 0
    for mote in sorted(t):
        if A == 1: return None
        while A <= mote:
            A += A - 1
            res += 1
        A += mote
    return res

def solve(A, m):
    best = len(m)
    for mask in xrange(1 << len(m)):
        t, c = [], 0
        for i in xrange(len(m)):
            if mask & (1 << i):
                t.append(m[i])
            else:
                c += 1
        res = check(A, t)
        if res is None: continue
        best = min(best, res + c)
    return best

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        A, N = map(int, f.readline().split(' '))
        m = map(int, f.readline().split())
        print 'Case #%d: %d' % (i + 1, solve(A, m))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
