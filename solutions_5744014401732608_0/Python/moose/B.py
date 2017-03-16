#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Solution for problem B of Google Code Jam 2016, Subround C.

How many DAGs are possible?
"""

__author__ = "Martin Thoma"
__email__ = "info@martin-thoma.de"

import pickle
import os


def make_graph(nr, nodes):
    """Generade an adjencency matrix."""
    get_bin = lambda x, n: format(x, 'b').zfill(n)
    digits = (nodes**2 + nodes) / 2
    edges = get_bin(nr, digits)
    g = []
    count = 0
    for i in range(nodes):
        row = []
        for j in range(nodes):
            if j <= i:
                row.append(0)
            else:
                row.append(int(edges[count]))
                count += 1
        g.append(row)
    return g


def count_paths(graph, maximum):
    """Count the number of paths from 0 to len(graph)-1."""
    paths = 0
    position_queue = [0]
    while len(position_queue) > 0 and paths < maximum:
        current_node = position_queue.pop()
        if current_node == len(graph) - 1:
            paths += 1
            continue
        for next_node, edge in enumerate(graph[current_node]):
            if edge:
                position_queue.append(next_node)
    return paths


def pre_compute(b_max=6, m_max=20):
    """Compute all solutions."""
    filename = "precompute.pickle"
    if os.path.isfile(filename):
        with open(filename, "rb") as f:
            solutions = pickle.load(f)
    else:
        solutions = {}
        # Generate graphs
        for b in range(2, b_max + 1):
            solutions[b] = {}
            for m in range(0, m_max + 1):
                solutions[b][m] = None
            digits = (b**2 + b) / 2
            print("m=%i, b=%i" % (m, b))
            for i in range(2**digits):
                g = make_graph(i, b)
                paths = count_paths(g, m_max + 1)
                if solutions[b][paths] is None:
                    solutions[b][paths] = g
                    print(solutions)
                if sum([1 for el in solutions[b].items() if el[1] is None]) == 0:
                    break
        with open(filename, "wb") as f:
            pickle.dump(solutions, f)
    return solutions


def format_graph(graph):
    """Format graph for code jam."""
    if graph is None:
        return "IMPOSSIBLE"
    s = "POSSIBLE"
    for row in graph:
        s += "\n%s" % "".join([str(el) for el in row])
    return s


def brute_force(b, m):
    """Solve problem B."""
    solutions = pre_compute()
    # print_solutions(solutions)
    return format_graph(solutions[b][m])


def print_solutions(solutions):
    for b, sol in sorted(solutions.items()):
        print("## b=%i" % b)
        for m, s in sorted(sol.items()):
            if s is None:
                string = "IMPOSSIBLE"
            else:
                string = "OK"
            print("  - m=%i: %s" % (m, string))


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(1, testcases + 1):
        b, m = [int(el) for el in raw_input().split()]
        print("Case #%i: %s" % (caseNr, brute_force(b, m)))
