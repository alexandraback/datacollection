#!/usr/bin/python

import sys

if len(sys.argv) != 2:
    print "Usage: ./pta <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
line = 1 #Represents current line in file
for i in range(1, ntests+1):
    info = data[line].strip().split()
    line+=1
    MaxE = int(info[0])
    currentE = MaxE
    Regen = int(info[1])
    Num = int(info[2])
    vals = data[line].strip().split()
    line+=1
    j = 0
    while j<len(vals):
        vals[j] = int(vals[j])
        j+=1
    Gain = 0
    validx = 0
    currentMax = max(vals)
    for val in vals:
        if val == currentMax:
            Gain += currentE*val
            if validx+1 < len(vals):
                currentMax = max(vals[validx+1:len(vals)])
            currentE = 0
        elif currentE > MaxE-Regen:
            Gain += (currentE-(MaxE-Regen))*val
            currentE -= (currentE-(MaxE-Regen))
        currentE += Regen
        validx+=1
    print "Case #%d: %d"%(i,Gain)
sys.exit(0)
