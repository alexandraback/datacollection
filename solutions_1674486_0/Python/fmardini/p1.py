import sys
from collections import defaultdict

class Graph(object):
    def __init__(self):
        self.parents = defaultdict(list)
        self.children = defaultdict(list)
        self.inherits_from = defaultdict(set)

    def add(self, i, l):
        a = map(int, l.strip().split(' '))
        i += 1 # 1 based
        num = a.pop(0)
        self.parents[i] = a
        for x in a:
            self.children[x].append(i)

    def solve(self):
        for k, v in self.parents.iteritems():
            self.inherits_from[k] = set(v)
        remaining = self.parents.keys()
        while remaining:
            g = None
            for k, v in self.parents.iteritems():
                if k in remaining and not v:
                    g = k
                    break
            remaining.remove(k)
            parents = set(self.inherits_from[g])
            parents.add(g)
            for y in self.children[g]:
                self.parents[y].remove(g)
                if parents.intersection(self.inherits_from[y]) - set([g]):
                    return "Yes"
                else:
                    self.inherits_from[y] = self.inherits_from[y].union(parents)
        return "No"

kases = int(sys.stdin.readline())
for k in range(kases):
    N = int(sys.stdin.readline().strip())
    g = Graph()
    for i in range(N):
        g.add(i, sys.stdin.readline())
    print("Case #%d: %s" % (k + 1, g.solve()))
