#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser
from z3 import *

def solve(J, P, S, K):
    solver = Optimize()

    var = {}

    for j in range(J):
        for p in range(P):
            for s in range(S):
                name = "x_{}_{}_{}".format(j, p, s)
                index = (j, p, s)
                x = Int(name)
                var[index] = x
                solver.add(x >= 0)
                solver.add(x <= 1)

    for j in range(J):
        for p in range(P):
            addends = []
            for s in range(S):
                addends.append(var[(j, p, s)])
            solver.add(Sum(*addends) <= K)

    for j in range(J):
        for s in range(S):
            addends = []
            for p in range(P):
                addends.append(var[(j, p, s)])
            solver.add(Sum(*addends) <= K)

    for p in range(P):
        for s in range(S):
            addends = []
            for j in range(J):
                addends.append(var[(j, p, s)])
            solver.add(Sum(*addends) <= K)

    maximize = []
    for p in range(P):
        for s in range(S):
            for j in range(J):
                maximize.append(var[(j, p, s)])

    solver.maximize(Sum(*maximize))

    c = solver.check()
    assert c == sat
    m = solver.model()

    solution = []
    for index, x in var.items():
        if m[x].as_long() == 1:
            #print index
            solution.append(index)

    #print len(solution)
    return solution


def main():
    inputfile = FileParser()
    T = inputfile.read_int()
    for test in range(1, T + 1):
        J, P, S, K = inputfile.read_integers()

        solution = solve(J, P, S, K)

        assert len(solution) <= 1000
        assert len(solution) <= J * P * S
        assert len(solution) >= 1

        print "Case #{}: {}".format(test, len(solution))
        for j, p, s in solution:
            print "{} {} {}".format(j+1, p+1, s+1)


if __name__ == '__main__':
    main()
