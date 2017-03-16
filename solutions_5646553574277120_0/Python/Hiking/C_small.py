#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import collections
import itertools

def get_availabes(targets, V):
    # print targets
    target = len(targets)
    availables = set()
    for i in xrange(1<<target):
        targstr = format(i, "b")[::-1]+"0"*target
        value = 0
        for j in xrange(target):
            if targstr[j] == "1":
                value += targets[j]
        if 0 < value <= V:
            availables.add(value)
    # print availables
    # print len(availables)
    return len(availables)


def solve(C,D,V,Ds):
    availables = get_availabes(Ds, V)
    if availables == V:
        print("Case #{}: {}".format(probnum, 0))
        return

    # print Ds
    # print get_availabes(Ds+[4], V)
    for i in xrange(1, V+1):
        for items in itertools.combinations(range(1, V+1), i):
            if get_availabes(list(set(Ds + list(items))), V) == V:
                print("Case #{}: {}".format(probnum, i))
                return


f_input = open(sys.argv[1])
problems = int(f_input.readline().rstrip())
for probnum in xrange(1, problems+1):
    C, D, V = map(int, f_input.readline().rstrip().split())
    Ds = map(int, f_input.readline().rstrip().split())
    solve(C,D,V,Ds)

