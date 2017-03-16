import sys
import itertools
import numpy as np
from collections import defaultdict


lines = sys.stdin.readlines()

ntests = int(lines[0])

curr = 1
for t in range(1, ntests+1):
    line = lines[curr+1].strip().split(" ")
    nums = [int(x) for x in line]
    maxNum = max(nums)


    bestTime = 9999
    for cs in range(1,maxNum+1):
        totalTime = 0
        for n in nums:
            cn = int(n/cs)
            if cn*cs<n:
                cn += 1
            totalTime += (cn-1)
            # print "c:", cs,cn
        totalTime += cs
        bestTime = min(bestTime,totalTime)
        # print "total:", totalTime
    # print "best:", bestTime


    curr += 2
    print "Case #"+ str(t) + ": " + str(bestTime)
    # print "\n\n\n"
