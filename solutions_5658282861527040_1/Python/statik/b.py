import linecache
from sys import argv
from math import log, ceil

filename = argv[1]
num = int(linecache.getline(filename, 1))

for c in range(2, num+2):
    A, B, K = map(int, linecache.getline(filename, c).strip().split(' '))
    total = min(A,K)*B + min(B,K)*A - min(A,K)*min(B,K)

    for i in xrange(K,A):
        for j in xrange(K,B):
            if i & j < K:
                total += 1

    print "Case #%i: %i" % (c-1, total)
