# https://code.google.com/codejam/contest/11254486/dashboard#s=p2
from hopcroftkarp import HopcroftKarp
from collections import defaultdict
filein = open('20161BC.in', 'r')
fileout = open('20161BC.out', 'w')

T = int(filein.readline())

for t in range(T):
    N = int(filein.readline())

    graph = defaultdict(set)
    X, Y = set(), set()
    for i in range(N):
        x, y = filein.readline().split(' ')
        X.add(x)
        Y.add(y)
        graph[x].add(y)
    mm = HopcroftKarp(dict(graph)).maximum_matching()
    ans = N - (len(X) + len(Y) - len(mm)) - len(mm) / 2

    fileout.write('Case #%d: %s \n' % (t + 1, str(ans)))

filein.close()
fileout.close()
