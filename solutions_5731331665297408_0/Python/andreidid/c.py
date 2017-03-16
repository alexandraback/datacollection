

import sys

from collections import defaultdict
from itertools import permutations

curent = None
pos = 0
p = None


def solution(p, graph):
    curent = p[0]
    pos = 0
   # print graph
    parents = []
    while pos < len(p) - 1:
        curent = p[pos]
        next = p[pos + 1]
 #       print pos, p, len(p), curent, graph[curent],next
        if next in graph[curent]:
            pos += 1
            parents.append(curent)
            continue
        found = False
        while len(parents):
            curent = parents.pop()
            for i in graph[curent]:
                if i == next:
                    pos += 1
                    parents.append(curent)
                    found = True
                    break
            if found:
                break
        if found:
            continue
       # print pos
        return False

    return True

def solve(f, t):
    n, m = map(int, f.readline().split())
    cities = []
    for i in xrange(n):
        cities.append(f.readline().strip())
    graph = defaultdict(lambda : [])
    back = defaultdict(lambda: [])
    for i in xrange(m):
        s, d = map(int, f.readline().split())
        s -= 1
        d -= 1
        graph[cities[s]].append(cities[d])
        graph[cities[d]].append(cities[s])
    m = float('inf')
    ret = ''
    for p in permutations(cities):
        if solution(p, graph):
            s = ''.join(p)
            number = int(s)
         #   print number
            if m > number:
                m = number
                ret = s
    return ret

if __name__=='__main__':
    f = sys.stdin
    T = int(f.readline())
    for t in xrange(T):
        ret = solve(f, t)
        print 'Case #%s: %s' % (t+1, ret)
