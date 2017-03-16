#!/usr/bin/python

N = int(raw_input())


def traverse(graph, node, visited):
    for child in graph[node]:
        if child in visited:
            return True
        else:
            visited.append(child)
    for child in graph[node]:
        if traverse(graph, child, visited):
            return True
    return False

def traverse_graph(graph, nodes):
    for node in xrange(1, nodes + 1):
        visited = [ node ]
        if (traverse(graph, node, visited)):
            return True
    return False


for case in xrange(0, N):
    print "Case #" + str(case + 1) + ":",

    graph = {}
    nodes = int(raw_input())
    for c in xrange(0, nodes):
        links = map(int, raw_input().split(" "))[1:]
        graph[c + 1] = links

    if traverse_graph(graph, nodes):
        print "Yes"
    else:
        print "No"

