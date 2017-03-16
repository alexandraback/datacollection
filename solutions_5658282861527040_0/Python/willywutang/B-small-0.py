def reader(inFile):
    a,b,k = inFile.getInts()
    return [a,b,k]

def solver(case):
    a,b,k = case
    count = 0
    for i in xrange(0,a):
        for j in xrange(0,b):
            c = i & j
            if c < k:
                count += 1
    return count 

# brute-forcing
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))   

# graphs 
def build_graph(edges):
    G = nx.Graph()
    for e in edges:
        [a,b] = e
        G.add_node(a)
        G.add_node(b)
        G.add_edge(a,b)
    return G
def degree_histogram(G):
    hist = Counter(nx.degree(G).values())   
    return hist

# binary search: find item in sorted list
def binary_search_aux(data,target,lo,hi):
    while lo <= hi:
        mid = (lo+hi)/2
        if data[mid] > target: # go down
            hi = mid-1
        elif data[mid] < target: # go up
            lo = mid+1
        else:
            return mid
    return False
def binary_search(data,target):
    return binary_search_aux(data,target,0,len(data)-1)

# binary search: find zero of a continuous function
def find_zero(f,lo,hi,k_max):
    """
    f = univariate function to find the zero of
    lo = lower bound on x 
    hi = upper bound on x
    k_max = number of iterations
    """
    k = 0
    while k < k_max:
        mid = float(lo+hi)/2
        if f(mid) > 0:
            hi = mid
        elif f(mid) < 0:
            lo = mid
        else:
            break
        k += 1
    return mid

if __name__ == "__main__":
    from GCJ import GCJ
    from itertools import chain, combinations, permutations, combinations_with_replacement
    from collections import Counter, defaultdict
    import networkx as nx
    import numpy as np
    import copy
    import random
    import datetime
    from math import log, sqrt, factorial, ceil
    from sympy import factorint, primerange, prime, divisors, nextprime, isprime, gcd
    from numpy import convolve
    from fractions import Fraction
GCJ(reader,solver,".","B").run()
