INPATH = r"C:\Users\Gil\Documents\jam\input.txt"
OUTPATH = r"C:\Users\Gil\Documents\jam\output.txt"

from fractions import Fraction
import math

def solveGame(data):
    part = data[0][0]
    #partSplit = part.split("/")
    frac = Fraction(part)
    num = float(frac)
    
    div =  ((2**40) / float(frac.denominator))
    if math.floor(div) != div:
        return "impossible"

    curCompare = 0.5
    curCount = 1

    for i in range(40):
        if num >= curCompare:
            return str(curCount)
        curCount += 1
        curCompare *= 0.5

    return "0"


data = open(INPATH,"r").readlines()
data = [x.replace("\n","") for x in data]
data = [[i for i in x.split(" ") ] for x in data]

numOfGames = int(data[0][0])

output = ""
curLine = 1

for i in range(numOfGames):
    firstRow = data[curLine:curLine+1][0]
    numberOfRows = 1 # int(firstRow[0]) + int(firstRow[1]) + 1
    output += "Case #%s: " % (i+1)
    output += solveGame(data[curLine:curLine+numberOfRows])
    output += "\n"
    curLine += numberOfRows

output = output.rstrip("\n")

print output

open(OUTPATH,"w").write(output)


    
