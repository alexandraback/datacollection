from sympy import *
from sympy.abc import *
import time
start = time.clock()
T = int(raw_input())
f = 2*n*r + n*(2*n - 1)
for i in range(1,T+1):
    a, b = map(int, raw_input().split())
    print "Case #{}: {}".format(i,int(max(solve(f.subs({'r':a})-b))))
print "Time Taken {} secs".format(time.clock() - start)
