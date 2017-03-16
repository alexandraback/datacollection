#!/usr/bin/env python

import sys

ls = sys.stdin.readlines()[1:]
i = 1
while len(ls) != 0:
    N = int(ls[0])
    es = [[int(x) for x in l.split()] for l in ls[1:(2*N)]]
    ls = ls[(2*N):]
    d = {}
    for e in es:
        for x in e:
            if x not in d:
                d[x] = 0
            d[x] += 1
    row = []
    for k in d:
        if d[k] % 2 == 1:
            row.append(k)
    row.sort()
    print "Case #%d: %s" % (i, " ".join(str(r) for r in row))
    i += 1
    
