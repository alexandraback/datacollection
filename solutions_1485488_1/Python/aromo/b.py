#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

GAP_NEEDED = 50
DROP_SPEED = 10
NEVER = 1e10
KAYAK_TIME = 1
WALK_TIME = 10
KAYAK_DEPTH = 20


def edges_from(nodes, N, M):
    for node in nodes:
        i, j = node
        if i+1 < N:
            yield(i, j, i+1, j)
        if i-1 >= 0:
            yield(i, j, i-1, j)
        if j+1 < M:
            yield(i, j, i, j+1)
        if j-1 >= 0:
            yield(i, j, i, j-1)
            
def all_nodes(N, M):
    for i in range(N):
        for j in range(M):
            yield(i, j)

def all_edges(N, M):
    return edges_from(all_nodes(N, M), N, M)


def solve_one():
    """ XXX the real code comes here """
    H, N, M = input_ints()
    ceil = zeros((N, M))
    for i in range(N):
        ceil[i] = array(input_ints())
    floor = zeros((N, M))
    for i in range(N):
        floor[i] = array(input_ints())

    # accessible: time square can first be entered
    # (1) at least gap between ceil and water
    accessible = (GAP_NEEDED + H - ceil) / DROP_SPEED
    # (2) least gap between ceil and floor,
    accessible[ceil - floor < GAP_NEEDED] = NEVER

    impassable = set([])
    for edge in all_edges(N, M):
        (i0, j0, i1, j1) = edge
        if floor[i1, j1] > ceil[i0, j0] - GAP_NEEDED:
            impassable.add(edge)
        elif floor[i0, j0] > ceil[i1,j1] - GAP_NEEDED:
            impassable.add(edge)

    earliest_reach = {}
    earliest_reach[(0,0)] = 0

    last_updated = set([(0,0)])
    
    while len(last_updated) > 0:
        newly_updated = set([])
        for edge in edges_from(last_updated, N, M):
            if edge in impassable:
                continue
            (i0, j0, i1, j1) = edge
            node0 = (i0, j0)
            node1 = (i1, j1)
            if (earliest_reach[node0] <= 0.) and (accessible[node1] <= 0.):
                if (not (node1 in earliest_reach)) or (earliest_reach[node1] > 0.):
#                    print "SPECIAL UPDATE", node0, node1
                    newly_updated.add(node1)
                    earliest_reach[node1] = 0.
                else:
                    continue
            else:
                start_time = max(earliest_reach[node0], accessible[node1])
                if H - start_time * DROP_SPEED >= floor[node0] + KAYAK_DEPTH:
                    travel_time = KAYAK_TIME
                else:
                    travel_time = WALK_TIME
                arrival_time = start_time + travel_time
                if arrival_time < 0.:
                    import pdb; pdb.set_trace()
                if not ((node1 in earliest_reach) and (earliest_reach[node1] <= arrival_time)):
#                    print "REGULAR UPDATE", node0, node1, arrival_time
                    newly_updated.add(node1)
                    earliest_reach[node1] = arrival_time
        last_updated = newly_updated

    # print
    # print earliest_reach
    # print
    # print earliest_reach[(N-1, M-1)]
    # print

    return earliest_reach[(N-1, M-1)]


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
