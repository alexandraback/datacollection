#!/usr/bin/env python
# -*- coding: utf-8 -*-

def lcs(v1, v2):
    a = (i for i in v1[::2])
    b = (i for i in v2[::2])

    el_a = sum(a)
    el_b = sum(b)

    a = (i for i in v1[::2])
    A = (i for i in v1[1::2])
    b = (i for i in v2[::2])
    B = (i for i in v2[1::2])

    result = 0
    ia = next(a)
    ib = next(b)
    iA = next(A)
    iB = next(B)
    indexA = 0
    indexB = 0
    while indexA < el_a and indexB < el_b:
        try:
            if iA == iB:
                result += min(ia, ib)
            if indexA < indexB:
                iA = next(A)
                ia = next(a)
                indexA += ia
            elif indexA > indexB:
                iB = next(B)
                ib = next(b)
                indexB += ib
            else:
                iA = next(A)
                ia = next(a)
                iB = next(B)
                ib = next(b)
                indexA += ia
                indexB += ib
        except:
            return result

t = int(raw_input().strip())
for ti in xrange(t):
    n, m = [int(j) for j in raw_input().strip().split(" ")]
    all_a = [int(j) for j in raw_input().strip().split(" ")]
    all_b = [int(j) for j in raw_input().strip().split(" ")]

    results = []
    for i in xrange(len(all_b)/2):
        results.append(lcs(all_a, all_b[i*2:]))
    for i in xrange(len(all_a)/2):
        results.append(lcs(all_a[i*2:], all_b))
    print "Case #{0}: {1}".format(ti+1, max(results))
