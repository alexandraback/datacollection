__author__ = 'lowikchanussot'

import itertools

def findsubsets(S,m):
    return set(itertools.combinations(S, m))

def getAllPossibleSums(Ds) :
    Ds = set(Ds)
    possible_values = set()
    for n in range(1, len(Ds) + 1) :
        subset = findsubsets(Ds, n)
        for s in subset :
            possible_values.add(sum(s))
    return possible_values


def GetMissingPossibleSums(sums, V) :
    sorted_sums = sorted(sums)
    prev = 0
    for s in sorted_sums :
        if s != prev + 1:
            return prev + 1
        else :
            prev = s
        if s >= V :
            return -1
    if prev < V :
        return prev+1
    return -1

def solveCAlgo(C, Ds, V) :
    new = 0
    done = False
    while not done :
        possible_values = getAllPossibleSums(Ds)
        miss = GetMissingPossibleSums(possible_values, V)
        if miss == -1 :
            return new
        else :
            new += 1
            Ds += [miss]


def solve_C(in_filename, out_filename):
    with open(in_filename, 'r') as file, open(out_filename, 'w') as ofile :
        lines = file.readlines()
        T = int(lines[0].strip())

        for case in range(0, T) :
            tokens = lines[2*case + 1].split()
            C, D, V = int(tokens[0]), int(tokens[1]), int(tokens[2])
            Ds = []
            for t in lines[2*case + 2].split() :
                Ds.append(int(t))
            sol = solveCAlgo(C, Ds, V)
            ofile.write("Case #%d: %d\n"%(case+1, sol))

if __name__ == '__main__':
    import sys
    import os
    _, input = sys.argv
    output = os.path.splitext(input)[0] + '_out.txt'
    solve_C(input, output)
