import collections
from heapq import * 

class Map:
    def __init__(self, zips, flights):
        self.n = len(zips)
        self.m = len(flights)
        self.zips = [int(z) for z in zips]
        self.flights = {}
        for f in flights:
            a, b = map(int, f.split())
            if a-1 in self.flights:
                self.flights[a-1].append(b-1)
            else:
                self.flights[a-1] = [b-1]
            if b-1 in self.flights:
                self.flights[b-1].append(a-1)
            else:
                self.flights[b-1] = [a-1]
        for c in self.flights.keys():
            self.flights[c] = self.sortbyz(self.flights[c])
        ps = [(int(zips[i]), i) for i in xrange(len(zips))]
        ps.sort()
        self.cbyz = [p[1] for p in ps]
        self.discovered = {}
    def sortbyz(self, cs):
        ps = [(self.zips[c], c) for c in cs]
        ps.sort()
        return [p[1] for p in ps]
    def bfs(self, c, banned = []):
        discovered = {}
        q = collections.deque()
        q.append(c)
        while q:
            d = q.popleft()
            if d not in discovered and d not in banned:
                q.extendleft(self.flights.setdefault(d, []))
                discovered[d] = True
        print c, len(discovered)
        return len(discovered)
    def stringify(self, traversal):
        s = ''
        for c in traversal:
            s += str(self.zips[c])
        return s
    def dfs(self, c):
        traversal = [c]
        self.discovered[c] = True
        for d in self.flights.setdefault(c, []):
            if d not in self.discovered:
                traversal += self.dfs(d)
        return traversal
    def solve(self):
        t = self.dfs(self.cbyz[0])
        return self.stringify(t)
"""
     #pick root
        root = self.cbyz[0]
        traversal = []
        qed = {root:True}
        h = []
        heappush(h, (self.zips[root], root))
        while h:
            _, v = heappop(h)
            traversal.append(v)
            for w in self.flights.setdefault(v, []):
                if w not in qed:
                    heappush(h, (self.zips[w], w))
                    qed[w] = True
        print traversal
        return self.stringify(traversal)
"""
"""
        for i in xrange(self.n):
            if self.bfs(self.cbyz[i]) == self.n:
                root = self.cbyz[i]
                break
        if root == None:
            raise Exception("noroot")
"""
            

class City:
    def __init__(self, zip):
        self.zip = zip
        self.flights = {}
    def addflight(self,cityid):
        self.flights[cityid] = True
    def flights(self):
        return self.flights
    def getzip(self):
        return zip
    

f = file('c.in', 'r')
lines = f.readlines()
n = int(lines[0])
f.close()

c = 1
g = file('c.out', 'w')
for i in xrange(n):
    print "case", i
    n, m = map(int, lines[c].split())
    prob = Map(lines[c+1:c+1+n], lines[c+1+n:c+1+n+m])
    ans = prob.solve()
    g.write("Case #{}: {}\n".format(i+1, ans))
    c += 1 + m + n
g.close()
