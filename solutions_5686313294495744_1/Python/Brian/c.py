from collections import defaultdict

with open("c.in") as f:
    t = int(next(f))
    for case in xrange(t):
        N = int(next(f).strip())
        cap = {"S": defaultdict(int), "T": defaultdict(int)}
        nodes = 0
        for i in xrange(N):
            x, y = next(f).strip().split(" ")
            x = "A_{}".format(x)
            y = "B_{}".format(y)

            if x not in cap:
                cap[x] = defaultdict(int)
                cap["S"][x] = 1
                nodes += 1
            if y not in cap:
                cap[y] = defaultdict(int)
                cap[y]["T"] = 1
                nodes += 1
            cap[x][y] += 1

        flow = 0
        while True:
            last = {}
            q = ["S"]
            visited = set(q)
            i = 0
            while i < len(q):
                x = q[i]
                i += 1
                for y, c in cap[x].iteritems():
                    if c > 0 and y not in visited:
                        visited.add(y)
                        q.append(y)
                        last[y] = x
                if "T" in visited:
                    break
            if "T" not in visited:
                break

            flow += 1
            y = "T"
            while y != "S":
                x = last[y]
                cap[x][y] -= 1
                cap[y][x] += 1
                y = x

        original_papers = flow + (nodes - 2*flow)

        print "Case #{}: {}".format(case+1, N - original_papers)
