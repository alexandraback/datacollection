#!/usr/bin/env python
# -*- coding: utf-8 -*-

import itertools

def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if not graph.has_key(start):
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths

t = int(raw_input().strip())
for ti in xrange(t):
    answer = "No"
    n = int(raw_input().strip())
    graph = {}
    for ni in xrange(n):
        links = [j for j in raw_input().strip().split(" ")]
        n_links = links.pop(0)
        if links:
            graph[str(ni+1)] = links
    for a,b in itertools.product(xrange(n), repeat=2):
        if a != b:
            paths = find_all_paths(graph, str(a+1), str(b+1))
            if len(paths) >= 2:
                answer = "Yes"
                break
    print "Case #{0}: {1}".format(ti+1, answer)
