#from __future__ import division

from Tools import gcj
#from __future__ import division
#from functools32.functools32 import lru_cache
import sys
import itertools
import os
import re
import string
import math
import sys
import heapq
from collections import namedtuple, defaultdict, deque
from Tools.gcj import printd
from copy import deepcopy
#from simpleai.search import SearchProblem, astar
import random
import operator
#from Tools import primes
#from itertools import product
import networkx as nx
from networkx.algorithms import flow

def build_graph(b, edges):
    g_w = nx.DiGraph()
    for i in xrange(b):
        g_w.add_node(i)
    #print edges
    g_w.add_edges_from(edges)
    return g_w

def possibilities(i, b):
    if i == 0:
        return range(1, b)
    elif i == b - 1:
        return []
    else:
        return range(1, i) + range(i+ 1,b)

def num_paths(g, b):
    sol = nx.all_simple_paths(g, 0, b - 1)
    c = 0
    for s in sol:
        c += 1
    return c

def build_res(edgeset, b):
    st = set(edgeset)
    res = "POSSIBLE"
    for i in xrange(0, b):
        res += "\n"
        for j in xrange(0, b):
            if (i, j) in st:
                res += "1"
            else:
                res += "0"
    return res
def contains_b(edge_set, b):
    cont = False
    for (s, t) in edge_set:
        if t == b - 1:
            cont = True
            break
    return cont

def has_dup(edge_set):
    dup = False
    for (a,b) in edge_set:
        if (b, a) in edge_set:
            dup = True
            break
    return dup

def solver(b, m):
    print "b", b, "m", m

    all_possibilities = [(i, p) for i in xrange(0, b) for p in possibilities(i, b)]
    print all_possibilities
    print b, len(all_possibilities) + 1
    for size in xrange(b-1, len(all_possibilities) + 1):
        #print "SIZE", size
        for edge_set in itertools.combinations(all_possibilities, size):
            edge_set = set(edge_set)
            if contains_b(edge_set, b) and not has_dup(edge_set):
                printd(edge_set)
                g = build_graph(b, edge_set)
                if num_paths(g, b) == m:
                    obj = next(nx.simple_cycles(g), None)
                    if obj == None:
                        return build_res(edge_set, b)

    return "IMPOSSIBLE"

def reader(in_file):
    """
    @type in_file: gcj.FileWrapper
    """
    (b, m) = in_file.getInts()

    return {
        'm': m,
        'b': b
    }


if __name__ == "__main__":
    ### GCJ module http://jamftw.blogspot.com.es/2012/05/python-code-jam-wrapper.html
    gcj.GCJ(reader, solver, os.getcwd(), "").run()
