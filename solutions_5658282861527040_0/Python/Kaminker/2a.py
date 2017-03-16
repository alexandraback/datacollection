INPATH = r"C:\Users\Gil\Documents\jam\input.txt"
OUTPATH = r"C:\Users\Gil\Documents\jam\output.txt"

import math

def solveGame(data):
    a = int(data[0][0])
    b = int(data[0][1])
    k = int(data[0][2])

    possibleK = min(a,b,k)
    count = 0

    smaller = min(a,b)
    larger = max(a,b)
    
    for curK in xrange(possibleK):
        for curA in xrange(curK, a):
            for curB in xrange(curK, b):
                if curA&curB == curK:
                    count+=1
            
    
    return str(count)
    
    


data = open(INPATH,"r").readlines()
data = [x.replace("\n","") for x in data]
data = [[i for i in x.split(" ") ] for x in data]

numOfGames = int(data[0][0])

output = ""

for i in range(numOfGames):
    output += "Case #%s: " % (i+1)
    output += solveGame(data[i+1:i+2])
    output += "\n"

output = output.rstrip("\n")

print output

open(OUTPATH,"w").write(output)


    
