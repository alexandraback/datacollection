#!/usr/bin/python
import sys

def doStuff(B, M):
    maxconnections = sum(range(0, B-1)) + 1
    if (maxconnections < M):
        return "IMPOSSIBLE"
    retstring = 'POSSIBLE\n'
    M-=1
    for i in range(B-1):
        # counts 1->B
        retstring += '0'
        retstring += '0'*i
        maxconntoadd = B - 2 - i
        if M > maxconntoadd:
            retstring += '1'*maxconntoadd
            M -= maxconntoadd
            retstring += '1\n'
        else:
            retstring += '1'*M
            retstring += '0'*(maxconntoadd - M)
            retstring += '1\n'
            M = 0
    retstring += '0'*B
    return retstring
    #return str(maxconnections)

inputfile = open(sys.argv[1])
outputfilename = sys.argv[2] if len(sys.argv) > 2 else 'output.txt'
outputfile = open(outputfilename, 'w')
numlines = int(inputfile.readline())
for i in range(numlines):
    B, M = (int(s) for s in inputfile.readline().split())
    outputfile.write("Case #" + str(i+1) + ": "
            +doStuff(B,M) + "\n")

