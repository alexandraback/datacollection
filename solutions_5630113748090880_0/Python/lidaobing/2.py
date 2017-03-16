import sys
import random





def foo(ifile):
    n = int(ifile.readline())
    count = {}
    for i in range(n*2-1):
        a = [int(x) for x in ifile.readline().split()]
        for x in a:
            if x not in count:
                count[x] = 0
            count[x] += 1
    res = []
    for x in count:
        if count[x] % 2 == 1:
            res.append(x)
    res.sort()
    return ' '.join([str(x) for x in res])





def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

main()

