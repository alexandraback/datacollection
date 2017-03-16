#!/usr/bin/env python

import numpy as np

for i in xrange(input()):
    a = np.zeros(10)
    N = input()
    k = 0
    if N==0:
        print "Case #{}: INSOMNIA".format(i+1)
        continue
    while (a == 0).any():
        k += N
        digits = list(set([int(j) for j in str(k)]))
        a[digits] = 1
    print "Case #{}: {}".format(i+1, k)


