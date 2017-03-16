import sys
import itertools
import numpy as np

lines = sys.stdin.readlines()

ntests = int(lines[0])

curr = 1
for t in range(1, ntests+1):
    n, line = lines[curr].strip().split(" ")
    n = int(n)
    nums = [int(x) for x in list(line)]

    d = 0
    s = 0
    for i,v in enumerate(nums):
        if v>0:
            d = max(d, i-s)
        s += v

    curr += 1

    print "Case #"+ str(t) + ": " + str(d)
