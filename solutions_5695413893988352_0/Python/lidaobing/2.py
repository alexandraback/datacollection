import sys
import random
sys.setrecursionlimit(10000)


def cool(i, a):
    ii = str(i)
    ii = '0'*(len(a)-len(ii)) + ii
    for j in range(len(a)):
        if a[j] == '?':
            continue
        if ii[j] != a[j]:
            return False
    return True

def foo2(i, j, n):
    return (abs(i-j), i, j)

def fmt(a, n):
    res = str(a)
    res = '0'*(n-len(res))+res
    return res

def foo(ifile):
    a,b = ifile.readline().split()
    n = len(a)
    res = []
    for i in range(10**n):
        if not cool(i, a):
            continue
        for j in range(10**n):
            if not cool(j, b):
                continue
            x = foo2(i, j, n)
            if x is not None:
                res.append(x)
    res.sort()
    return fmt(res[0][1], n) + ' ' + fmt(res[0][2], n) 






def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

main()

