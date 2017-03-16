# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import sys

# <codecell>
num_cases  = sys.stdin.readline()

def solve(s):
    total_set = set(range(10))
    base_n = int(s)
    if base_n == 0:
    	return "INSOMNIA"
    max_digits = len(s)+2
    n = base_n
    while total_set and len(str(n)) < max_digits:
        total_set -= set([int(x) for x in str(n)])
        n += base_n
    if len(total_set) > 0:
        return "INSOMNIA"
    return n - base_n

for num, line in enumerate(sys.stdin):
    print "Case #{0}: {1}".format(num+1, solve(line))

# <codecell>


