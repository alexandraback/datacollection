import sys
import collections
import heapq


def readpair(s):
    return map(int, s.split())


def main():
    f = open(sys.argv[1])
    for j in xrange(int(f.readline())):
        n,m = readpair(f.readline())
        zips = [int(f.readline().strip()) for x in xrange(n)]
        edges = [(a-1,b-1) for (a,b) in (readpair(f.readline()) for x in xrange(m))]
        edgedict = collections.defaultdict(list)
        for (a,b) in edges:
            edgedict[a].append(b)
            edgedict[b].append(a)

        start = min((i for i in xrange(n)), key = lambda i: zips[i])
        #print zips, edgedict, start

        dtime = dict()
        low = dict()
        artic = set()
        def search1(city):
            dtime[city] = len(dtime)
            low[city] = dtime[city]
            for neigh in edgedict[city]:
                if neigh not in dtime:
                    search1(neigh)
                    low[city] = min(low[city], low[neigh])
                    if low[neigh] >= dtime[city]:
                        artic.add(city)
                else:
                    low[city] = min(low[city], dtime[neigh])
        search1(start)
        for v in edgedict:
            if len(edgedict[v]) == 1:
                artic.add(v)

        visited = set()
        sequence = []
        def search(start):
            city = start
            queue = [(zips[city], city)]
            stack = [city]
            dfss = dict()
            parent = dict()
            while queue:
                zip,city = heapq.heappop(queue)
                if city in visited: continue
                visited.add(city)
                sequence.append(city)

                if city in parent and stack[-1] != parent[city]:
                    for d in dfss[stack.pop()]:
                        search(d)

                es = [e for e in edgedict[city] if e not in visited]
                for e in es:
                    if e not in artic:
                        heapq.heappush(queue, (zips[e], e))
                        parent[e] = city
                df = sorted((e for e in es if e in artic), key = lambda i: zips[i])
                while df and ((not queue) or (zips[df[0]] < queue[0][0])):
                    search(df.pop(0))

                dfss[city] = df
                stack.append(city)

            for d in dfss.get(start, []):
                search(d)


        search(start)
        print "Case #%i: %s" % (j+1 , "".join(str(zips[i]) for i in sequence))




main()