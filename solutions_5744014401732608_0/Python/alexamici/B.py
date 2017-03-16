"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes:
    python -u X.py < X-test.in > X-test.out
may be python 2 or 3.
"""
from __future__ import print_function

import os
import sys
#sys.setrecursionlimit(20000)


def common_setup():
    #import memcache as mc
    #C = mc.Client(['127.0.0.1:11211'])
    pass


def case_reader(tc, infile):
    P = map(int, next(infile).split())
    del infile
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    import itertools as it
    import networkx as nx
    import time

    B, M = P
    start = time.time()
    for SB in it.product([0, 1], repeat=B * (B - 1)):
        if time.time() > start + 200.:
            res = 'IMPOSSIBLE'
            break
        skip = False
        G = nx.DiGraph()
        for i, s in enumerate(SB):
            x, y = i // B, i % B
            if x >= y and s:
                skip = True
                break
            if s:
                G.add_edge(x, y)
        if not skip and 0 in G and B - 1 in G and nx.is_directed_acyclic_graph(G):
            mm = len(list(nx.all_simple_paths(G, 0, B-1)))
            if mm == M:
                res = 'POSSIBLE\n' + '\n'.join(''.join(str(v)for v in SB[i*B:(i+1)*B]) for i in range(B - 1)) + '\n' + '0' * B
                break
    else:
        res = 'IMPOSSIBLE'
    return 'Case #{:d}: {}'.format(tc, res)


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print(case_solver(**case))
