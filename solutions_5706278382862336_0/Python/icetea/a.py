import sys 
import math
ds = [int(math.pow(2,x)) for x in range(1,41)]
d = {}
for x in range(1,41): d[int(math.pow(2,x))] = x
lines = sys.stdin.readlines()
for i in range((int(lines[0]))):
    p, q = lines[i+1].strip().split("/")
    p = int(p)
    q = int(q)
    if q not in ds: print "Case #"+str(i+1)+": impossible"
    else:
        ans = d[q]
        m  = 0
        for x in range(1,41):
            if p > math.pow(2,x): m += 1
        print "Case #"+str(i+1)+": "+str(ans-m)
