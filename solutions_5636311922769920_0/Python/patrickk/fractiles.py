#!/usr/bin/env python

import sys

with open(sys.argv[1]) as f:
    f.readline()
    x = 1
    for line in f:
        K, C, S = map(int, line.split())
        tiles = [K ** (C - 1) * i + 1 for i in range(K)]
        print "Case #%d: %s" % (x, " ".join(map(str, tiles)) if K <= S else "IMPOSSIBLE")
        x += 1

