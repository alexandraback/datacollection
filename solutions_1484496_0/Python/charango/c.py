
def solve(S):
    top = pow(2, 20)
    res = {}
    for i in xrange(1, top):
        a, b = [], 1
        for j in xrange(20):
            if i & b: a.append(S[j])
            b *= 2
        a.sort()
        s = sum(a)
        if s in res and res[s] != a:
            return res[s], a
        res[s] = a

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        S = map(int, f.readline().split(' '))
        N = S.pop(0)
        res = solve(S)
        print 'Case #%d:' % (i + 1)
        if res:
            set1, set2 = res
            print ' '.join(map(str, set1))
            print ' '.join(map(str, set2))
        else:
            print 'Impossible'

if __name__ == '__main__':
    import sys
    main(sys.stdin)
