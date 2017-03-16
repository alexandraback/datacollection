#!/usr/bin/env python

################################################################################
#
# Google Code Jam - 2016
#
# Round 1C - Problem C -
#
# Joaquin Derrac - carrdelling@gmail.com
#
################################################################################

import sys
from collections import defaultdict

def naive(j, p, s, k):

    ps = defaultdict(int)
    jp = defaultdict(int)
    js = defaultdict(int)

    outfits = []

    for c in xrange(s):
        for b in xrange(p):
            if ps[(b,c)] == k:
                continue
            for a in xrange(j):
                if jp[(a,b)] == k:
                    continue
                if js[(a,c)] == k:
                    continue
                if ps[(b,c)] == k:
                    continue
                jp[(a,b)] += 1
                js[(a,c)] += 1
                ps[(b,c)] += 1
                outfits.append((a+1,b+1,c+1))

    output = []
    output.append(str(len(outfits)))
    for outfit in outfits:
        output.append(' '.join(map(str, outfit)))

    return '\n'.join(output)

def test(solution, k):

    ps = defaultdict(int)
    jp = defaultdict(int)
    js = defaultdict(int)

    outfits = []

    counter = 0
    for a in xrange(j):
        for b in xrange(p):
            for c in xrange(s):
                if solution[counter] == '1':
                    jp[(a,b)] += 1
                    js[(a,c)] += 1
                    ps[(b,c)] += 1
                    outfits.append((a+1,b+1,c+1))
                    if jp[(a,b)] > k:
                        return []

                    if js[(a,c)] > k:
                        return []

                    if ps[(b,c)] > k:
                        return []

                counter += 1

    return outfits

def solve(j, p, s, k):
    solutions = []

    if j + p + s > 8:
        return naive(j,p,s,k)

    all_garments = j*p*s

    for code in xrange(1,(2 ** all_garments)):
        solution = ("{0:0b}").format(code)
        while len(solution) < all_garments:
            solution = '0' + solution
        solutions.append(solution)

    best_solution = [0] * all_garments
    n = 0
    for solution in solutions:
        repres = test(solution, k)
        if len(repres) > 0:
            new_n = sum([1 for i in solution if i == '1'])
            if new_n > n:
                n = new_n
                best_solution = repres

    output = []
    output.append(str(n))
    for o in best_solution:
        output.append(' '.join(map(str, o)))

    return '\n'.join(output)


input_path = sys.argv[1]

with open(input_path) as input_file:

    n_cases = int(input_file.readline().strip())

    for case in xrange(1, n_cases+1):
        j, p, s, k = map(int,input_file.readline().strip().split())
        solution = solve(j, p, s, k)
        print 'Case #{0}: {1}'.format(case, solution)
