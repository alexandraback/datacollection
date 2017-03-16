__author__ = 'caseyvu'

import sys, math

def readInput(fileName):
    global inputData

    inputFile = open(fileName)

    inputFile.readline() # number of test cases
    dataLine = False
    for line in inputFile:
        if dataLine:
            dataLine = False
            inputData.append([int(n) for n in line.strip().split(' ')])
        else:
            dataLine = True

def splitCostIndividual(maxPancake, totalPancakes):
    return int(math.ceil(float(totalPancakes)/maxPancake)) - 1
    
def costWithMaxPancake(maxPancake, initial):
    splitCost = 0
    for totalPancakes in initial:
        splitCost = splitCost + splitCostIndividual(maxPancake, totalPancakes)
        
    return splitCost + maxPancake
    
def minCost(initial):
    minCost = None
    maxFromInitial = max(initial)
    for maxPancake in range(1,maxFromInitial+1):
        cost = costWithMaxPancake(maxPancake, initial)
        if minCost is None or minCost > cost:
            minCost = cost
    return minCost

inputData = []
readInput(sys.argv[1])

for i in range(len(inputData)):
    #print inputData[i]
    print "Case #{0}: {1}".format(i+1, minCost(inputData[i]))
    