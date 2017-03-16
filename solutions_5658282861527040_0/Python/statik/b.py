import linecache
from sys import argv

filename = argv[1]
num = int(linecache.getline(filename, 1))

for c in range(2, num+2):
    A, B, K = map(int, linecache.getline(filename, c).strip().split(' '))
    total = 0

    for i in xrange(A):
        for j in xrange(B):
            if i & j < K:
                total += 1

    print "Case #%i: %i" % (c-1, total)
