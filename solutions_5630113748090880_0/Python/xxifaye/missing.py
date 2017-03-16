import sys
from collections import defaultdict

def solve():
    n = int(sys.stdin.readline())
    c = defaultdict(int)
    for i in xrange(2*n-1):
        s = map(int, sys.stdin.readline().split())
        for ss in s:
            c[ss] += 1
    ret = []
    for i in c:
        if c[i] % 2 != 0:
            ret.append(i)
    ret.sort()
    ret = map(str, ret)
    return ' '.join(ret)

if __name__ == '__main__':
    c = int(sys.stdin.readline())
    for i in xrange(c):
        print 'Case #%s: %s' % (i + 1, solve())
