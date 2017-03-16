import sys
from collections import defaultdict
from fractions import gcd
from math import factorial

sums = [1, 1]

for i in range(10):
    sums.append(sum(sums))
    

T = int(sys.stdin.readline())

    
case = 1
for case in range(1, T+1):
    B, M = map(int, sys.stdin.readline().strip().split())
    #print B, M, sums[B-1]
    if M <= sums[B-1]:
        left = M
        needed = "0"
        for i in range(B-2,-1,-1):
            if left >= sums[i]:
                left -= sums[i]
                needed += "1"
            else:
                needed += "0"
        print "Case #{0}:".format(case), "POSSIBLE"
        print needed
        for i in range(B-1):
            print ("0"*(i+2)) + ("1"*(B-i-2))
    else:
        print "Case #{0}:".format(case), "IMPOSSIBLE"
        
#print sums
