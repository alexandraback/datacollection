

import sys

def solve(f, t):
    a, b, k = map(int, f.readline().split())
    ret = 0
    for i in xrange(a):
        for j in xrange(b):
            if i & j < k:
                ret += 1
    return ret

if __name__=='__main__':
    f = sys.stdin
    T = int(f.readline())
    for t in xrange(T):
        ret = solve(f, t)
        print 'Case #%s: %s' % (t+1, ret)
