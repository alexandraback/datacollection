#! /usr/bin/python

import os, sys

def debug(msg):
    if len(sys.argv) > 1 and sys.argv[1] == '-d':
        sys.stderr.write(msg)
        sys.stderr.write('\n')

T = int(sys.stdin.readline())
input_data = {}

def get_min_index(cities_zip):
    l_min = cities_zip[0]
    l_idx = 0
    for i in range(0, len(cities_zip)):
        if cities_zip[i] < l_min:
            l_idx = i
            l_min = cities_zip[i]
    return l_idx

def solve_brute(N, cities_zip, graph, full_path, first_visited_path):
    if full_path == []:
        if len(first_visited_path) < N:
            return "LETTERSAREBIGGERTHANNUMBERS"
        else:
            this_path = "".join(str(cities_zip[i]) for i in first_visited_path)
            return this_path
    this_hop = full_path[-1]
    next_hop_list = [(cities_zip[v], v)
                     for v in graph[this_hop]
                     if v not in first_visited_path]
    if next_hop_list != []:
        next_hop = min(next_hop_list)
        return min(
            solve_brute(N, cities_zip, graph,
                        full_path + [next_hop[1]],
                        first_visited_path + [next_hop[1]]),
            solve_brute(N, cities_zip, graph,
                        full_path[:-1],
                        first_visited_path))
    else:
        return solve_brute(N, cities_zip, graph,
                        full_path[:-1],
                        first_visited_path)

def solve(N, M, cities_zip, graph):
    start = get_min_index(cities_zip)
    ret = solve_brute(N, cities_zip, graph, [start], [start])
   
    return ret

# For each test case
for t in range(1, T+1):
    [N, M] = [int(x) for x in sys.stdin.readline().split(' ')]
    cities_zip = []
    graph = []
    for i in range(0, N):
        w = int(sys.stdin.readline().strip('\n'))
        cities_zip.append(w)
        graph.append([])
    for i in range(0, M):
        inp = sys.stdin.readline()
        debug('inp = %s' % inp)
        [s, d] = [int(x) for x in inp.split(' ')]
        graph[s-1].append(d-1)
        graph[d-1].append(s-1)
    debug('graph = %s' % graph)
    ret = solve(N, M, cities_zip, graph)
    sys.stdout.write('Case #%s: %s\n' % (t, ret))
