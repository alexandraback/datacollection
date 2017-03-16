#!/usr/bin/python

import sys
import math

min_req = [0, 10, 19, 109, 199, 1099, 1999, 10999, 19999, 109999, 199999, 1099999, 1999999, 10999999, 19999999]

infile=sys.argv[1]

lines = [line.strip() for line in open(infile)]

num_cases=int(lines[0])

for case in xrange(1, num_cases+1):
    n = int(lines[case])
    n_str = lines[case]
    n_len = len(n_str)
    ret = 0;

    if n <= 20:
        print "Case #" + str(case) + ":", n 
        continue

    for x in xrange(0, n_len):
        ret = ret + min_req[x]


    start = 10**(n_len-1)
    if start == n:
        print "Case #" + str(case) + ":", ret 
        continue

    midpt = int(math.floor(float(n_len)/2))
    upper_mid = int(n_str[0:midpt])
    lower_mid = int(n_str[midpt:])
    if lower_mid == 0:
        upper_mid -= 1
    add = int(str(upper_mid)[::-1])
    if add != 1:
        ret = ret + add
    start = start + add
    start = int(str(start)[::-1])
    add = n - start + 1
    ret = ret + add
    print "Case #" + str(case) + ":", ret
