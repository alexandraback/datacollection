#!/usr/bin/python

"""
Kingdom Rush problem solution
(GCJ 2012, Round 1A)
Author: a5kin
"""

import sys

# open input file
if len(sys.argv) == 2 and sys.argv[1] != '--help':
    in_file = open(sys.argv[1])
else:
    print "Usage: kingdom_rush.py <input file>"
    sys.exit(0)

# get number of cases
T = int(in_file.readline())

# begin prosessing cases
for cur_case in range(T):
    # get constants
    N = int(in_file.readline())
    a = []
    b = []
    rules = []
    for i in range(N):
        rules.append(map(int, in_file.readline().split(" ")))
    rules.sort(key=lambda x: x[1])
    rules.reverse()
    for A, B in rules:
        a.append(A)
        b.append(B)
    num_competes = 0
    num_complete = 0
    cur_stars = 0
    possible = True
    while num_complete < N and possible:
        possible = False
        for i in range(N):
            if b[i] >= 0 and b[i] <= cur_stars:
                b[i] = -1
                if a[i] >= 0:
                    a[i] = -1
                    cur_stars += 2
                else:
                    cur_stars += 1
                num_complete += 1
                num_competes += 1
                possible = True
                break
        if not possible:
            for i in range(N):
                if a[i] >= 0 and a[i] <= cur_stars:
                    a[i] = -1
                    cur_stars += 1
                    num_competes += 1
                    possible = True
                    break
    if not possible:
        num_competes = "Too Bad"
    # output results
    print "Case #%d: %s" % (cur_case + 1, num_competes)

# close input file
in_file.close()

    
        
