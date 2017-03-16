import sys
import Queue
import collections

def visit(city, path, stack, cities, flights, paths):

    if len(path) == len(cities):
        paths.append(path)
        return

    if city:
        stack = [city] + list(stack)

    for flight in flights[city]:
        if flight in path:
            continue
        visit(flight, tuple(list(path) + [flight]), stack, cities, flights, paths)

    if not path:
        return

    while len(stack) > 1:
        stack.pop(0)
        last = stack[0]
        for flight in flights[last]:
            if flight in path:
                continue
            visit(flight, tuple(list(path) + [flight]), stack, cities, flights, paths)

def process(cities, flights):
    cities.sort()
    for city, flight in flights.iteritems():
        flight.sort()
    flights[None] = cities

    paths = []
    visit(None, tuple([]), [], cities, flights, paths)
    #print paths
    return min(paths)

def main():
    cases = int(sys.stdin.readline())

    for case in range(cases):
        N, M = map(int, sys.stdin.readline().strip().split())

        cities = []
        for _ in range(N):
            cities.append(int(sys.stdin.readline().strip()))

        flights = collections.defaultdict(list)
        for _  in range(M):
            i, j = map(int, sys.stdin.readline().strip().split())
            X = cities[i - 1]
            Y = cities[j - 1]
            flights[X].append(Y)
            flights[Y].append(X)

        path = process(cities, flights)

        print 'Case #%d: %s' % (case + 1, ''.join(map(str, path)))

if __name__ == '__main__':
    main()
