#!/usr/bin/python

"""
Password Problem problem solution
(GCJ 2012, Round 1A)
Author: a5kin
"""

import sys

# open input file
if len(sys.argv) == 2 and sys.argv[1] != '--help':
    in_file = open(sys.argv[1])
else:
    print "Usage: password_problem.py <input file>"
    sys.exit(0)

# get number of cases
T = int(in_file.readline())

# begin prosessing cases
for cur_case in range(T):
    # get constants
    A, B = map(int, in_file.readline().split(" "))
    prob = map(float, in_file.readline().split(" "))
    def correct_prob(num_signs):
        p = 1
        for i in range(num_signs):
            p *= prob[i]
        return p
    enter_keys = B + 2
    keep_prob = correct_prob(A)
    keep_keys = keep_prob * (B - A + 1) + (1 - keep_prob) * (B * 2 - A + 2)
    keys = min(enter_keys, keep_keys)
    for i in range(1, A+1):
        back_prob = correct_prob(A - i)
        back_keys = back_prob * (B - A + 1 + i * 2) + (1 - back_prob) * (B * 2 - A + 2 + i * 2)
        keys = min(keys, back_keys)
    # output results
    print "Case #%d: %s" % (cur_case + 1, keys)

# close input file
in_file.close()

    
        
