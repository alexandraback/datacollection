#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def howBigDoIget(A, motes):
    while len(motes) > 0 and A > min(motes):
        A += min(motes)
        motes.remove(min(motes))
    return A

def stepsNeededForNext(A, motes):
    m = min(motes)
    steps = 0
    if m >= 1 and A == 1:
        return 10**12
    while A <= m:
        A += (A-1)
        steps += 1
    return steps

def solve(A, motes):
    steps = 0
    A = howBigDoIget(A, motes)
    while len(motes) > 0 and A <= max(motes):
        if (stepsNeededForNext(A, motes) >= len(motes)):
            steps += len(motes)
            return steps
        else:
            A += (A-1)
        A = howBigDoIget(A, motes)
        steps += 1
    return steps
 
if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases+1):
        A, N = map(int,raw_input().split(" "))
        motes = sorted(map(int,raw_input().split(" ")))
        copyed = motes[:]
        solution = solve(A, motes)
        if solution > N:
            sys.stderr.write("Somethings wrong!\n")
            sys.stderr.write("A:" + str(A) + "\n")
            sys.stderr.write(str(copyed) + "\n")
            sys.stderr.write(str(solution) + "\n")
            sys.stderr.write(str(N) + "\n")
            solution = N
        print("Case #%i: %s" % (caseNr, solution))
