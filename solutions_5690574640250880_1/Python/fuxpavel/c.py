import sys
import time

def mines(r, c, m):
    x = {}
    free = r*c - m
    min_dim = min(r, c)
    for i in xrange(r):
        for j in xrange(c):
            x[i, j] = "*"
    if m == r*c:
        return -1
    if m == 0:
        for i in xrange(r):
            for j in xrange(c):
                x[i, j] = "."
        x[0, 0] = "c"    
        return x
    if m == r*c -1:
        x[0, 0] = "c"
        return x
    if min_dim == 1:
        for i in xrange(r):
            for j in xrange(c):
                if free > 0:
                    x[i, j] = "."
                    free -= 1
        x[0, 0] = "c"
        return x
    if min_dim == 2:
        if m % 2 == 1 or free < 4:
            return -1
        for i in xrange(r):
            for j in xrange(c):
                if free > 0:
                    if c == 2:
                        x[i, j] = "."
                    else:
                        x[j, i] = "."
                    free -= 1
        x[0, 0] = "c"
        return x
    if free/float(min_dim) >= 3:
        for i in xrange(r):
            for j in xrange(c):
                if free > 0:
                    x[i, j] = "."
                    free -= 1
                else:
                    break
        free = r*c - m
        i = free / c
        j = free % c
        if j == 1:
            x[i-1,c-1] = "*"
            x[i,j] = "."
        x[0, 0] = "c"
        return x
    if free < 9 and free not in [1, 4, 6, 8]:
        return -1
    
    if free in [4, 6]:
        first = free/2
        for i in xrange(first):
            for j in xrange(first):
                if free > 0:
                    x[i, j] = "."
                    free -= 1
        x[0, 0] = "c"
        return x
    first = min(int(round(free-2)/2.0), r)
    for i in xrange(r):
        for j in xrange(first):
            if free > 0:
                x[i, j] = "."
                free -= 1
    x[0, 0] = "c"
    return x

    
    
f = open(sys.argv[1])
cases = int(f.readline().strip())

for i in xrange(1, cases + 1):
    r, c, m = [int(j) for j in f.readline().strip().split()]
    start = time.time()
    result = mines(max(r, c), min(r, c), m)
    print "Case #%d:" % i
    if result == -1:
        print "Impossible"
    else:
        if r == max(r, c):
            for i in xrange(r-1, -1, -1):
                print "".join([result[i, j] for j in xrange(c)][::-1])
        else:
            for j in xrange(r-1, -1, -1):
                print "".join([result[i, j] for i in xrange(c)][::-1])
    #print "Case #%d: %f" % (i, result)
