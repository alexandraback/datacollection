#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from heapq import heappush, heappop

def dijkstra(G, v, src):
    dist = [float('inf')]*v
    dist[src] = 0
    heap = [(dist[src], src)]
    while heap:
        node_dist, node = heappop(heap)
        for child, child_dist in G[node]:
            # print child
            if node_dist + child_dist < dist[child]:
                dist[child] = node_dist + child_dist
                heappush(heap, (node_dist + child_dist, child))
    return dist

def main():
    graphV = [[] for _ in xrange(10**6 + 1)]
    for x in xrange(10**6):
        graphV[x].append((x + 1, 1))
        graphV[x].append((int(str(x)[::-1]), 1))
    sssp = dijkstra(graphV, 10**6 + 1, 0)
    sssp.append(sssp[-1] + 1)
    for test in xrange(int(raw_input())):
        n = int(raw_input())
        print "Case #%s: %s" % (test + 1, sssp[n])

main()
