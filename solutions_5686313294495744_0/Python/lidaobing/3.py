import sys
import random

def xx(idx):
    res = 0
    while idx > 0:
        res += idx % 2
        idx //= 2
    return res

def foo2(a, s, idx2, n):
    idx = idx2
    res = [0, 0]
    for i in range(n):
        if idx % 2 == 1:
            res[0] |= a[i][0]
            res[1] |= a[i][1]
        idx //= 2
    if tuple(res) == tuple(s):
        return xx(idx2)
    return 1000

def transfer(a):
    pp = {}
    ss = {}
    aa = []
    pa = 1
    sa = 1
    for x, y in a:
        if x not in pp:
            pp[x] = pa
            pa = pa*2
        if y not in ss:
            ss[y] = sa
            sa = sa*2
        aa.append([pp[x], ss[y]])
    #print pp, ss
    return aa, [pa-1, sa-1]


def foo(ifile):
    n = int(ifile.readline())
    a = [ifile.readline().split() for  i in range(n)]
    a,s = transfer(a)
    res = n
    for i in range(2**n):
        if xx(i) >= res:
            continue
        res = min(res, foo2(a, s, i, n))
    return n-res


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

main()

