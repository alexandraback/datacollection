
# usage:  (py3 a.py < a.in) > a.out

import time, sys, inspect
from hopcroftkarp import HopcroftKarp

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+':', *a, file=sys.stderr, **k)
map = lambda *a: list(__builtins__.map(*a))
reversed = lambda *a: list(__builtins__.reversed(*a))

#---------------------------------------------

'''

so we have tuples of numbers
    (a1, b1)
    (a2, b2)
    (a2, b1)
    with left and right numbers non-overlapping
    -> bipartite undirected graph

'longest-path-algorithm?'
    crossing from RTL

uses one unique word => is real!
    we can do an implication chain to find out rite!?

what if we have all duplicates?
    real
        (1,2)
        (3,4)
    fake
        (1,4)
        (3,2)
    impossible to find fake
    ((1,4),(3,2) could be orig and others fake)
    => non-constructive task

wait
    paths of len 3 or more imply at least one fake
    (but len 4 doesn't imply 2 fakes)

omg
    maximum matching in bipartite graph!!
    we had this in discrete structures :D

'''

def run(data):

    graph = dict()

    # build graph for bipartite maximum-matching
    for a,b in data:
        a = 'A_' + a
        b = 'B_' + b

        if a not in graph:
            graph[a] = set([b])
        else:
            graph[a] |= set([b])

        # if b not in graph:
        #     graph[b] = set([a])
        # else:
        #     graph[b] |= set([a])

    # number of edges in left / right half of graph
    left = set()
    right = set()
    for a,b in data:
        left |= set([a])
        right |= set([b])

    x = HopcroftKarp(graph).maximum_matching()
    num_optimal = round(len(x) / 2)
    num_real_topics = num_optimal + (len(left) - num_optimal) + (len(right) - num_optimal)

    return len(data) - num_real_topics

#---------------------------------------------

def read_case():
    m = int(input())
    return [input().split() for i in range(m)]

for i in range(int(input())):
    outstr = 'Case #'+str(i+1)+': '+str(run(read_case()))
    print(outstr, ' @ t =', time.clock())
    __builtins__.print(outstr)



