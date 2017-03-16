import sys
from Queue import PriorityQueue
from collections import defaultdict

lines = [map(int, line.strip().split(' ')) for line in sys.stdin.readlines()]
T = lines[0][0]

line = 1
for t in range(T):
    N, M = lines[line]
    cities = [l[0] for l in lines[line + 1: line + N + 1]]
    travels = lines[line + 1 + N: line + N + M + 1]
    destinations = defaultdict(set)
    for a, b in travels:
        # print a, b
        destinations[a - 1].add(b - 1)
        destinations[b - 1].add(a - 1)
    line += N + M + 1

    q = PriorityQueue()
    for i, city in enumerate(cities):
        q.put(([i], "START %d" % i, [i], [], i))

    solution = []
    while not q.empty():
        priority, moves, route, returns, city = q.get()
        # print moves, route, returns, city

        if returns == [] and len(route) == N:
            solution = route
            break

        # outbound options
        for d in destinations[city]:
            if d not in route:
                q.put(([cities[c] for c in (route + [d])],
                       moves + " GOTO %d-%d" % (city, d),
                       route + [d],
                       returns + [city],
                       d))

        # return option
        if returns:
            d = returns[-1]
            q.put(([cities[c] for c in route],
                   moves + " RETURN %d-%d" % (city, d),
                  route,
                  returns[:-1],
                  d))


    sol = "".join(str(cities[r]) for r in solution)
    print "Case #%d: %s" % (t + 1, sol)
