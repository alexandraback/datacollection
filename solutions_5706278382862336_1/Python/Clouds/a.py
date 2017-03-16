#!/usr/bin/python

import sys
import fractions
import math
fin=sys.stdin
T=int(fin.readline())

bb=[2**x for x in range(41)]

for i in range(T):
    [a,b]=[int(x) for x in fin.readline().split('/')]
    d=fractions.gcd(a,b)
    a,b=a/d,b/d
    if not b in bb:
        print("Case #%d: impossible"%(i+1))
    else:
        #print(a,b)
        [a,b]=[int(math.log(x,2)) for x in [a,b]]
        #print(a,b)
        print("Case #%d: %d"%(i+1,b-a))

