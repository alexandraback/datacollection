from sys import stdin
from math import sqrt

for cn in xrange(1,1+int(stdin.readline())):
    [D,N,A] = stdin.readline().split()
    D = float(D)
    [N,A] = [int(z) for z in [N,A]]
    dists = [[float(k) for k in stdin.readline().split()] for i in xrange(N)]
    accs = [float(k) for k in stdin.readline().split()]
    print "Case #%d:" % cn
    othtimetoreach = 0
    if (N == 2 and dists[0][1] < D):
        othtimetoreach = (float(D - dists[0][1]) * (dists[1][0] - dists[0][0])) / (dists[1][1] - dists[0][1])
    for acc in accs:
        timetoreach = max(sqrt(2 * D / acc),othtimetoreach)
        print timetoreach
