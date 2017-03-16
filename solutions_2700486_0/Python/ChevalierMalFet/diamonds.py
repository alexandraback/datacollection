from scipy.misc import *

filename = "B-small-attempt2.in"
outputname = filename + 'out.txt'

inFile = open(filename, 'r')
outFile = open(outputname, 'w')

numTests = int(inFile.readline())


def calcProb(numBlocks, x, y):
    n = abs(x) + abs(y)
    if (numBlocks >= ((n+2)*(n+1))/2):
        return 1
    elif (numBlocks <= (n*(n-1)/2)):
        return 0
    elif (x == 0):
        return 0
    else:
        numSplitters = numBlocks - (n*(n-1)/2)
        levelMax = n*2 + 1
        if (numSplitters - n > y):
            return 1
        accum = 0
        for i in range(y+1, numSplitters+1):
            accum += comb(numSplitters, i)
        return accum*1.0/(2**numSplitters)

for i in range(numTests):
    test = inFile.readline().split()
    numBlocks = int(test[0])
    x = abs(int(test[1]))
    y = abs(int(test[2]))
    prob = calcProb(numBlocks, x, y)
    outFile.write("Case #" + str(i+1) + ": " + str(prob) + '\n')
    print "Case #" + str(i+1) + ": " + str(prob)

inFile.close()
outFile.close()
