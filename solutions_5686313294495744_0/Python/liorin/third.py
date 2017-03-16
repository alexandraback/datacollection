# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys
from collections import Counter

# <codecell>


# <codecell>

num = int(sys.stdin.readline())
for n in range(1, num+1):
    l = []
    n_topics = int(sys.stdin.readline())
    for i in range(n_topics):
        f,s = sys.stdin.readline().split()
        l.append([f,s])
    d_f = set()
    d_s = set()
    fakes = 0
    for x in l:
        f = x[0]
        s = x[1]
        if (not f in d_f) and (not s in d_s):
            d_f.add(f)
            d_s.add(s)
	    l.remove(x)
    for x in l:
        f = x[0]
        s = x[1]
        if (f in d_f) and (s in d_s):
            fakes += 1
        if not f in d_f:
            d_f.add(f)
        if not s in d_s:
            d_s.add(s)
    print "Case #{0}: {1}".format(n, fakes)

