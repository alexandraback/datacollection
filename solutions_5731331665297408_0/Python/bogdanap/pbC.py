input = open('input', 'r')
output = open('output', 'w')

from collections import defaultdict
from itertools import permutations

def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if not graph.has_key(start):
        return None
    for node in graph[start]:
        if node not in path:
            newpath = find_path(flights, node, end, path)
            if newpath: return newpath
    return None

def solution(p, flights):
    curent = p[0]
    pos = 0
    up = []
    while pos < len(p)-1:
        curent = p[pos]
        next = p[pos + 1]
        if next in flights[curent]:
            pos += 1
            up.append(curent)
            continue
        found = False
        while len(up):
            curent = up.pop()
            for i in flights[curent]:
                if i == next:
                    pos += 1
                    up.append(curent)
                    found = True
                    break
            if found:
                break
        if found:
            continue
        return False
    return True

testcases = int(input.readline().strip())
for testcase in xrange(1, testcases+1):
    cities, flight_no = input.readline().strip().split(' ')
    cities= int(cities)
    zips = []
    flights = defaultdict(list)
    for i in xrange(cities):
        zip = input.readline().strip()
        zips.append(zip)
    for i in xrange(int(flight_no)):
        c1, c2 =  input.readline().strip().split(' ')
        c1 = int(c1)
        c2 = int(c2)
        flights[zips[c1-1]].append(zips[c2-1])
        flights[zips[c2-1]].append(zips[c1-1])
    visited = {i:False for i in xrange(1, cities+1)}
    result = ''
    #first = cities.index(min(zips)) + 1
    #visited[first] = True
    m = float('inf')
    for p in permutations(zips):
        if solution(p, flights):
            number = int( ''.join(p))
            if m > number:
                m = number
                result =  ''.join(p)
    output.write("Case #%s: %s\n" % (testcase, result))

input.close()
output.close()
