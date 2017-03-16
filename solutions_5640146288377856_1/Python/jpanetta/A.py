import math, sys, numpy as np;

l = list(sys.stdin);
T = int(l[0]);
l = l[1:];
for t in range(T):
    R,C,W = map(int, l[0].strip().split(' '));

    probes = (C - 1) / W;
    lastRow = probes + W;

    prevRows = C / W

    guaranteed = max(R - 1, 0) * prevRows + lastRow

    print "Case #%i: %i" % (t + 1, guaranteed);
    l = l[1:];
