#!/usr/bin/python

from sys import argv

inputf = open(argv[1], 'r')
outputf = open('results.out', 'w')

outputbuffer = []

for i, line in enumerate(inputf.readlines()[1:], start = 1):
    resutlstring = 'Case #{0}: '.format(i)
    dat = [int(n) for n in line.split()]
    N = dat[0]
    S = dat[1]
    p = dat[2]
    scores = dat[3:]
    
    n_matches = 0
    n_surprises = 0
    for s in scores:
        tri = [s/3]*3
        adjuster = s - sum(tri)
        for j in range(adjuster):
            tri[j] += 1
        best = max(tri)
        if best >= p:
            n_matches += 1
            print "Best score for {0}:".format(str(s)), tri
            continue
        elif n_surprises < S:
            k = 0
            while max(tri) < min(tri) + 2 and k <= 2:
                if tri[1 + k%2] == 0:
                    k += 1
                    continue
                tri[1 + k%2] -= 1
                tri[0] += 1
                k += 1
            if max(tri) > min(tri) + 2:
                k -= 1
                tri[1 + k%2] += 1
                tri[0] -= 1
            if tri[0] >= p:
                n_matches += 1
                n_surprises += 1
                print "Best score for {0}:".format(str(s)), tri, "(*)"
    
    resutlstring += str(n_matches) + '\n'
    outputbuffer += [resutlstring]

outputf.writelines(outputbuffer)
