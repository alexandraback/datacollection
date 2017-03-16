#!/usr/bin/python

"""
Diamond Inheritance problem solution
(GCJ 2012, Round 1C)
Author: a5kin
"""

import sys

# open input file
if len(sys.argv) == 2 and sys.argv[1] != '--help':
    in_file = open(sys.argv[1])
else:
    print "Usage: diamond_inheritance.py <input file>"
    sys.exit(0)

# get number of cases
T = int(in_file.readline())

# begin prosessing cases
for cur_case in range(T):
    # get constants
    N = int(in_file.readline().strip())
    inherit = []
    for i in range(N):
        inherit.append(map(int, in_file.readline().split(" "))[1:])
    # calculate ancestors
    ancestors = [[] for i in range(N)]
    def build_ancestors(i):
        #recursive function for all ancestors search
        if not ancestors[i] and inherit[i]:
            ancestors[i] += inherit[i]
            for j in inherit[i]:
                build_ancestors(j-1)
                ancestors[i] += ancestors[j-1]
    for i in range(N):
        build_ancestors(i)
    # seek double ancestors
    has_inheritance = False
    for i in range(N):
        d = {}
        for j in range(len(ancestors[i])):
            if d.has_key(ancestors[i][j]):
                has_inheritance = True
                break
            else:
                d[ancestors[i][j]] = True
        if has_inheritance:
            break
    if has_inheritance:
        has_inheritance = "Yes"
    else:
        has_inheritance = "No"
    # output results
    print "Case #%d: %s" % (cur_case + 1, has_inheritance)

# close input file
in_file.close()

    
        
