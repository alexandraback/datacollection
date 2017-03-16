#/usr/bin/env python

import sys, os
from math import ceil

# the first line is the total number of cases
cases_total = int(sys.stdin.readline().strip())

case = 0                                # id of the case
while case < cases_total:
    case += 1                           # iterate case id

    # do your input here
    line = sys.stdin.readline()

    [ R, C, W ] = [ int(x) for x in line.strip().split() ]

    # let's consider each row separately
    # firstly, to cover each row
    #     the first shot at x=W covers [1,2W-1]
    #     subsequent shots extend the range by W
    #     the relationship is k*W+(W-1), where k is the number of shots taken
    if ( C==W ):
        k = 1
    else:
        k = (C-(W-1))/(W)
        if ( C - k*W - (W - 1) ) > 0:
            k += 1
    n_min = k*R
    # one shot must have hit
    # our search-space is reduced to C - (k-1)*W
    search = C - (k-1)*W
    # we know that position x=W in the search space is already hit
    # we can expect 1 miss due to position shifting, then W-1 to take out the rest of the ship
    n_min += W
    # unless the search space is W (i.e. C % W == 0)
    # in which case we cannot miss
    if ( search == W):
        n_min -= 1

    # set your output here
    out = str(n_min)

    print "Case #"+str(case)+": "+out   # the output format is 'Case #${case}: ${output}'
