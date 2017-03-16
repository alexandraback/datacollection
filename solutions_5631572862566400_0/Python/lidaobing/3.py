import sys
import random


def cc(n, i):
    if i == 1:
        for x in n:
            yield [x]
        return

    if len(n) == i:
        yield n[:]
        return


    for x in cc(n[1:], i):
        yield x

    for x in cc(n[1:], i-1):
        yield [n[0]] + x


def yy2(n, i):
    if i == 1:
        for x in n:
            yield [x]
        return

    for idx in range(len(n)):
        for x in yy2(n[:idx] + n[idx+1:], i-1):
            yield [n[idx]] + x

def yy(n, i):
    n2 = list(range(1, n+1))
    for x in cc(n2, i):
        for x2 in yy2(x[1:], i-1):
            if x2[0] < x2[-1]:
                yield [x[0]] + x2

def foo3(a, x):
    #print x
    for i in range(len(x)):
        i1 = x[i-1]
        i2 = x[(i+1)%len(x)]
        if a[x[i]-1] not in [i1, i2]:
            return False
    return True

def foo2(a, i):
    for x in yy(len(a), i):
        if foo3(a, x):
            return True
    return False


def foo(ifile):
    n = int(ifile.readline())
    a = [int(x) for x in ifile.readline().split()]
    for  i in range(n, 0, -1):
        if foo2(a, i):
            return i

def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

main()

