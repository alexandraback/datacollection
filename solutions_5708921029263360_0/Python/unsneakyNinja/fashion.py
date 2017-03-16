#!/usr/bin/python
import sys

def doStuff(J, P, S, K):
    if (J*P*K < J*P*S):
        print "K"
        maxcombos = J*P*K
        retstring = str(maxcombos) + "\n"
        scounter = 0
        for i in range(K):
            for j in range(J):
                for k in range(P):
                    retstring += str(j+1) + " " 
                    retstring += str(k+1) + " " 
                    retstring += str(((i+j+k)%S)+1) + "\n"
                    #scounter = (scounter + 1)%S
        return retstring
    maxcombos = J*P*S
    print "S"
    retstring = str(maxcombos) + "\n"
    for i in range(J):
        for j in range(P):
            for k in range(S):
                retstring += str(i+1) + " " 
                retstring += str(j+1) + " " 
                retstring += str(k+1) + "\n"
    return retstring
    



inputfile = open(sys.argv[1])
outputfilename = sys.argv[2] if len(sys.argv) > 2 else 'output.txt'
outputfile = open(outputfilename, 'w')
numlines = int(inputfile.readline())
for i in range(numlines):
    J,P,S,K = (int(s) for s in inputfile.readline().split())
    outputfile.write("Case #" + str(i+1) + ": "
            +doStuff(J,P,S,K) )

