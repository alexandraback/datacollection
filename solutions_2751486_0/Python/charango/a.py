
cons = 'bcdfghjklmnpqrstvwxyz'

def valid(s, n):
    r = 0
    for c in s:
        if c in cons:
            r += 1
            if r == n: return True
        else:
            r = 0
    return False

def solve(S, N):
    L = len(S)
    res = 0
    for i in xrange(L):
        for j in xrange(i + N, L + 1):
            if valid(S[i:j], N):
                res += 1
    return res

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        S, N = f.readline().split(' ')
        print 'Case #%d: %d' % (i + 1, solve(S, int(N)))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
