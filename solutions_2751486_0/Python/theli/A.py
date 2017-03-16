from sys import stdin

T = int(stdin.readline())
vovels = ['a', 'e','i', 'o', 'u']
for i in xrange(1,T+1):
    result = 0
    L, n = stdin.readline().split()
    n = int(n)
    subs = []
    cur = 0
    for x in xrange(len(L)):
        if L[x] not in vovels:
            cur += 1
        else:
            cur = 0
        if cur >= n:
            subs.append(x)

    l = len(L)
    visited = set()
    for s in subs:
        x = s - n + 2
        y = x + n
        for a in xrange(x):
            for b in xrange(y, l + 2):
                if (a, b) not in visited:
                    result += 1
                    visited |= set([(a,b)])

    print 'Case #{0}: {1}'.format(i, result)
