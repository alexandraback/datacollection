import sys
import math

t = int(raw_input())

def solve(r,t) :
    return (-(2*r-1) + math.sqrt((2*r-1)*(2*r-1)+8*t))/4

for i in range(t):
    r, t = raw_input().split()
    print "Case #%d: %d" % (i+1,int(solve(int(r),int(t))))
