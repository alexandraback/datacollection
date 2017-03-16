#!/usr/bin/python
import sys
import itertools
import os
import re
import string
import math
import sys
import heapq
from collections import namedtuple



def solve_tickets(n, edges1, edges2, ordering):
    #print "trying: ", ordering, edges1, edges2
    visited = set()
    back = {}

    if n == 1:
        return True

    current_index = 0
    current = ordering[current_index]

    next_index = current_index + 1
    next = ordering[next_index]


    visited.add(current)
    #print visited, back, current
    while len(visited) < n or len(back) > 0:
        #print "searching", current, "to", next
        #search for an outbound edge to go to next
        if current in edges1 and next in edges1[current]:
            #print "fly from ", current, "to", next
            # edge used, fly to next city
            edges1[current].remove(next)
            edges2[next].remove(current)
            back[next] = current
            visited.add(next)
            current = next
            current_index = next_index
            if len(visited) < n:
                next_index = current_index + 1
                next = ordering[next_index]
        elif current in edges2 and next in edges2[current]:
            #print "fly from ", current, "to", next

            # edge used, fly to next city
            edges2[current].remove(next)
            edges1[next].remove(current)
            back[next] = current
            visited.add(next)
            current = next
            current_index = next_index
            if len(visited) < n:
                next_index = current_index + 1
                next = ordering[next_index]
        elif current in back:
            # go backwards
            old_current = current
            new_current = back[current]
            del back[old_current]
            current = new_current
            #print "going back from",old_current, "to", new_current
        else:
            #no movement possible
            break


    return len(back) == 0 and len(visited) == n

def calculate_cost(p, zips):
    string = ''
    for i in xrange(len(p)):
        string += zips[p[i] - 1]
    return string

def solver(params):
    m = params['m']
    n = params['n']
    edges = params['edges']
    zips = params['zips']
    print n, m, edges, zips

    min_cost = None
    perm = itertools.permutations(xrange(1, n+1))
    for p in perm:
        edges1 = {}
        edges2 = {}
        for (a, b) in edges:
            if a in edges1:
                edges1[a].append(b)
            else:
                edges1[a] = [b]

            if b in edges2:
                edges2[b].append(a)
            else:
                edges2[b] = [a]

        if solve_tickets(n, edges1, edges2, p):
            # calculate cost with p
            #print "worked", p
            cost = calculate_cost(p, zips)
            #print "worked", p, "cost", cost

            if min_cost is None:
                min_cost = cost
            else:
                min_cost = min(cost, min_cost)

    return min_cost

def reader(in_file):
    parts = in_file.readline().strip().split(' ')
    n = int(parts[0])
    m = int(parts[1])
    zips = []
    for i in xrange(n):
        zip = in_file.readline().strip()
        zips.append(zip)

    edges = []
    for i in xrange(m):
        parts = in_file.readline().strip().split(' ')
        source = int(parts[0])
        target = int(parts[1])
        edges.append((source, target))


    return {'n': n, 'm': m, 'edges': edges, 'zips': zips}


if __name__ == "__main__":
    from gcj import GCJ
    import os
    GCJ(reader, solver, os.getcwd(), "c").run()

