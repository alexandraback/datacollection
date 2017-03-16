#!/usr/bin/python

import sys
import re
import math
import fractions
import numpy

f = open(sys.argv[1],'r')
num = int(f.readline())
for z in range(num):
    s = [int(x) for x in f.readline().split()]
    n = s[0]
    del s[0]
    szip = zip(s,range(n))
    smin, list_ind = zip(*sorted(szip))
    ssum = sum(s)
    list_ind = numpy.argsort(s)
    remsum = ssum
    index = 1
    while index < len(smin):
        if remsum > index*(smin[index] - smin[index-1]):
            remsum -= index*(smin[index] - smin[index-1])
            index += 1
        else:
            break
    votes = [0.0]*n
    for i in range(index):
        votes[i] = 100.0*(smin[index-1] - smin[i] + float(remsum)/index) / ssum
    #print ssum, smin, index, remsum, votes
    #print s
    output = [0.0]*n
    for i in range(n):
        output[list_ind[i]] = str(votes[i])
    #output = [str(votes[x]) for x in list_ind]
    print 'Case #{}:'.format(z+1), ' '.join(output)
    sys.stdout.flush()
