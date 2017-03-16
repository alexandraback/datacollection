# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys



def count_flips(s):
    # given a string s of + and - signs, count how many flips are needed to get all +
    if (len(s) == 0):
    	return 0
    prev = s[0]
    count = 0
    for c in s[1:]:
    	if c == '-' or c == '+':
        	if c != prev:
            		count += 1
            		prev = c
            
    if prev == '-':
        #if the last segment is -, then we need to flip the whole thing at the end
        count += 1
        
    return count

# <codecell>

sys.stdin.readline()
for num, line in enumerate(sys.stdin):
    print "Case #{0}: {1}".format(num+1, count_flips(line))

# <codecell>


