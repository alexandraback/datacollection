from sys import stdin
from numpy import *

T = int(stdin.readline())
for t in range(1,T+1):
    N = int(stdin.readline())

    blocks = sorted(
        [ (-float(word),i)
            for i in range(2)
            for word in stdin.readline().strip().split() ]
    )

    owner = array([1-2*b[1] for b in blocks], dtype=int)
    print "Case #"+str(t)+":", N+min(cumsum(owner)), max(cumsum(owner))
