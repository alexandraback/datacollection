from __future__ import print_function

if __name__ == '__main__':
    T = int(raw_input())
    for pb_i in xrange(T):
        N, M = [int(_) for _ in raw_input().split()]
        cities = []
        for i in xrange(N):
            cities.append(raw_input())

        flight = {}
        for c in cities:
            flight[c] = []

        for i in xrange(M):
            src, dest = [int(_) for _ in raw_input().split()]
            if dest < len(cities) and src < len(cities):
                flight[cities[dest]].append(cities[src])
                flight[cities[src]].append(cities[dest])
        
        cities.sort()
        unvisited = list(cities)
        n_cities = list(cities)

        c = None
        all_flight = []
        visited = []
        while(len(visited) < N):
            if c:
                all_flight += flight[c]
            c = n_cities.pop(0)
            unvisited.remove(c)
            visited.append(c)
            for c in unvisited:
                if c in all_flight:
                    n_cities.append(c)

        ret = ""
        for v in visited:
            ret += v
        print("Case #{}: {}".format(pb_i+1, ret))

