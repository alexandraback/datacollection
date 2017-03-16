#!/usr/bin/env python3

import sys
from collections import defaultdict

def read_ints():
    return [int(s) for s in input().split()]

def main():
    no_cases, = read_ints()
    for case in range(1, no_cases+1):
        N, = read_ints()
        scheme = []
        for cls in range(N):
            bcnt, *bases = read_ints()
            assert bcnt == len(bases)
            scheme.append(bases)
        print('Case #%d: %s' % (case, solve(scheme)))

def visit(topo, visited, cls, children):
    if cls in visited:
        return
    visited.add(cls)
    for base in children[cls]:
        visit(topo, visited, base, children)
    topo.append(cls)

def solve(scheme):
    children = {n+1: set() for n in range(len(scheme))}
    parents = {}
    topo, visited = [], set()
    for cls, bases in enumerate(scheme, 1):
        parents[cls] = set(bases)
        for base in bases:
            children[base].add(cls)
    topo, visited = [], set()
    for cls, bases in enumerate(scheme, 1):
        if bases: continue
        visit(topo, visited, cls, children)
    assert(visited == set(range(1, len(scheme) + 1)))
    assert(set(topo) == set(range(1, len(scheme) + 1)))
    ancestors = dict(parents.items())
    for cls in reversed(topo):
        chals = [{p}|ancestors[p] for p in parents[cls]]
        counts = defaultdict(lambda: 0)
        for chal in chals:
            for c in chal:
                counts[c] += 1
        if any(c > 1 for c in counts.values()):
            return 'Yes'
        ancestors[cls].update(set().union(*chals))
    return 'No'

if __name__ == '__main__':
    main()
