#!/usr/bin/python
import os, sys, math

global best_matrix

def max_energy(max_e, e, r, values, i):
    global best_matrix
    if (i == (len(values) - 1)):
        return e*values[i]
    if (e, i) in best_matrix:
        return best_matrix[(e, i)]
    # try all E values, good enough for small
    best = 0
    best_index = -1
    for energy_to_use in range(0, e+1):
        total_energy = energy_to_use*values[i] + max_energy(max_e, min(e-energy_to_use+r, max_e), r, values, i+1)
        if total_energy > best:
            best = total_energy
            best_index = energy_to_use

    #print "e = %d i = %d returning %d (best_index %d)" % (e, i, best, best_index)
    best_matrix[(e, i)] = best
    return best

def solve(e, r, values):
    global best_matrix
    best_matrix = {}
    # dynamic programming
    best = max_energy(e, e, r, values, 0)
    return best

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (e, r, n) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        values = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #answer = solve_fast(r, t)
        answer = solve(e, r, values)
        #print caseStr
        print "Case #%d: %d" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
