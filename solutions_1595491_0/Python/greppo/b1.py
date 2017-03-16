#!/usr/bin/python
"Dancing with the Googlers"
import sys
dbg = 'debug' in sys.argv

f = open(sys.argv[1])
T = int(f.readline())
for X in range(1, T+1):
    vals = [int(x) for x in f.readline().split()]
    N, S, p = vals[:3]
    t = sorted(vals[3:])
    # lowest total that can be a surprise triplet with max=p
    tL = max(p + 2*(p-2), p)
    # lowest total that can be a non-surprise triplet with max=p
    tH = max(p + 2*(p-1), p)
    no, maybe, yes = 0, 0, 0
    for ti in t:
        if ti < tL:
            no += 1
        elif ti < tH:
            maybe += 1
        else:
            yes += 1
    A = yes + min(S, maybe)
    print "Case #{}: {}".format(X, A)
