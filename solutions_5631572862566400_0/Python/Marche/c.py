#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        N = int(input())
        succ = {k: -1 for k in range(N)}
        prev = {k: set() for k in range(N)}
        for node, neighbor in enumerate(map(int, input().split())):
            succ[node] = neighbor-1
            prev[neighbor-1].add(node)

        cycles = []
        paths = []
        for node in range(N):
            path = [node]
            nxt = succ[node]
            while nxt not in path:
                path.append(nxt)
                nxt = succ[nxt]
            cycles.append(path[path.index(nxt):])
            paths.append(path[:path.index(nxt)+1])
        
        maxcyc = max(len(c) for c in cycles)
        pathlen = []
        for cyc in cycles:
            if len(cyc) == 2:
                a, b = cyc
                pathlen.append(max(len(p) for p in paths if p[-1] == a) + max(len(p) for p in paths if p[-1] == b))

        
        debug(cycles)
        debug(paths)
        debug(pathlen)
        result = max(maxcyc, max(pathlen, default=0))
        if maxcyc == 2:
            result = N

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
