#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

def solve(N, inherits):
    leaves = []
    rev_inherits = {}
    for c in range(N, 0, -1):
        parents = inherits[c]
        if len(parents) == 0:
            leaves.append(c)
        for p in parents:
            if p in rev_inherits:
                rev_inherits[p].add(c)
            else:
                rev_inherits[p] = set([c])

    assert len(leaves) != 0
    for leaf in leaves:
        if check(leaf, inherits, rev_inherits) == "Yes":
            return "Yes"

    return "No"

def check(node, map, rmap, paths = []):
    if len(paths) == 0:
        paths = set([node])

    children = rmap.get(node, False)
    if not children:
        return "No"
    
    print("check: ch %s, paths %s" % (children, paths))
    if children & paths:
        return "Yes"
    paths |= children
    for child in children:
        result = check(child, map, rmap, paths)
        if result == "Yes":
            return result

    return "No"

# main
me = sys.argv[0].split("/")[-1].replace(".py", "")
file = me + "-sample"
file = me + "-small-attempt0"
#file = me + "-large"

with open(file + ".in", "r") as fdin:
    with open(file + ".out", "w") as fdout:

        T = int(fdin.readline())
        for ncase in range(T):
            N = int(fdin.readline())
            inherits = {}
            for i in range(N):
                data = [int(x) for x in fdin.readline().split()]
                assert data[0] == len(data[1:])
                inherits[i + 1] = set(data[1:])
                
            result = solve(N, inherits)
    
            line = "Case #%d: %s" % (ncase + 1, result)
            print(line) 
            fdout.write("%s\n" % line)
