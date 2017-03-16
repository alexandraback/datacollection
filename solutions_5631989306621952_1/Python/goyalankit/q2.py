#!/usr/bin/env python

inFile = open('in.txt', 'r')
outFile = open('out.txt' ,'w')
t = int(inFile.readline())

for case in range(1,t+1,1):
    instring = inFile.readline()
    instring = instring[:-1]
    outstring = instring[0]
    for i in range(1,len(instring),1):
        if instring[i] >= outstring[0]:
            outstring = instring[i] + outstring
        else:
            outstring += instring[i]
    outFile.write('Case #{}: {}\n'.format(case, outstring))
        
