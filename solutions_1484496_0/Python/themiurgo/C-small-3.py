#!/usr/bin/env python
# -*- coding: utf-8 -*-

import itertools

t = int(raw_input().strip())
for i in xrange(t):
    integers = [int(j) for j in raw_input().strip().split(" ")]
    n = integers[0]
    s = integers[1:]
    sums = {}
    break_again = False
    for l in xrange(1,len(s)-1):
        for a_tuple in itertools.combinations(s, l):
            tuple_sum = sum(a_tuple)
            if tuple_sum in sums:
                if sums[tuple_sum] != a_tuple:
                    break_again = True
                    break
            sums[tuple_sum] = a_tuple
        if break_again:
            break
    tuple_1 = ' '.join([str(a) for a in a_tuple])
    tuple_2 = ' '.join([str(a) for a in sums[tuple_sum]])
    if tuple_1 != tuple_2:
        print "Case #{0}:\n{1}\n{2}".format(i+1, tuple_1, tuple_2)
    else:
        print "Case #{0}:\nImpossible".format(i+1, tuple_1, tuple_2)
