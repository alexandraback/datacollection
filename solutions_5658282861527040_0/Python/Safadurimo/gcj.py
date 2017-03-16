import sys
import itertools
import numpy as np

#takes some minutes to run


# open input files and read in into lines
filename = "input.txt"
inputFromFile=True
if inputFromFile: inp = open(filename)
else: inp=sys.stdin

# Precomputation



def solveTestCase(a,b,k):
    count=0;
    for i in range(a):
        for j in range(b):
            if(i&j<k): count+=1

    return str(count)


T =int(inp.readline())

for t in range(1,T+1):
    a,b,k = [int(x) for x in (inp.readline().split())]
    print "Case #%d: %s"  % (t,solveTestCase(a,b,k))
