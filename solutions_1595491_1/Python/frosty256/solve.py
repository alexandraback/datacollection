#!/usr/bin/python

from sys import argv
from recycling import find_recycled

inputf = open(argv[1], 'r')
outputf = open('result.out', 'w')

inputbuffer = inputf.readlines()[1:]
outputbuffer = []
for i, line in enumerate(inputbuffer, start=1):
    A, B = [int(c) for c in line.split()]
    n_sols = find_recycled(A, B)
    outputbuffer.append('Case #{0}: '.format(str(i)) + str(n_sols) + '\n')

outputf.writelines(outputbuffer)
