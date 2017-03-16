#!/usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
cases = int(fin.readline())
for i in range(0, cases):
    r, v = fin.readline().split()
    r, v = int(r), int(v)
    # print r, v
    area = 0
    n = 0
    while True:
        area = 2*n*n + 2*n*r - n
        # print area
        n += 1
        if area > v:
            break
        # print n
        
    print "Case #%d: %d" % (i+1, n - 2)


    
