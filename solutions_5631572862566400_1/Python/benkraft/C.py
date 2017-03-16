#!/usr/bin/env python
import collections
import itertools


def cycles(graph):
    """list of cycles, dict of node -> index of cycle it's in"""
    cycle_members = set()
    large_cycles = []
    two_cycles = []
    two_cycle_targets = {}
    for i in xrange(len(graph)):
        crumbs = []
        seen = set()  # set(crumbs)
        while True:
            if i in seen:
                # we have a cycle.
                cycle = crumbs[crumbs.index(i):]
                if len(cycle) > 2:
                    large_cycles.append(cycle)
                else:
                    two_cycles.append(cycle)
                    two_cycle_targets[cycle[0]] = len(crumbs) - 2
                    two_cycle_targets[cycle[1]] = 0
                cycle_members.update(cycle)
                break
            elif i in cycle_members:
                # we made it to an existing cycle
                if i in two_cycle_targets:
                    two_cycle_targets[i] = max(two_cycle_targets[i],
                                               len(crumbs))
                break
            else:
                crumbs.append(i)
                seen.add(i)
                i = graph[i]
    return large_cycles, two_cycles, two_cycle_targets


def solve(testcase):
    graph = [i - 1 for i in testcase]
    large_cycles, two_cycles, two_cycle_targets = cycles(graph)
    if large_cycles:
        max_cycle = max(map(len, large_cycles))
    else:
        max_cycle = 0
    two_cycle_sizes = [two_cycle_targets[a] + two_cycle_targets[b] + 2
                       for a, b in two_cycles]
    two_cycle_sizes.sort()
    return max(max_cycle, sum(two_cycle_sizes))


def parse(lines):
    return [map(int, line.split()) for line in lines[1::2]]


if __name__ == '__main__':
    with open('C.in') as inf:
        with open('C.out', 'w') as outf:
            results = map(solve, parse(list(inf)[1:]))
            for i, line in zip(itertools.count(1), results):
                outf.write("Case #%s: %s\n" % (i, line))
