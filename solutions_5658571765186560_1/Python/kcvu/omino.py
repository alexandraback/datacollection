__author__ = 'caseyvu'

import sys

def readInput(fileName):
    global inputData

    inputFile = open(fileName)

    inputFile.readline() # number of test cases
    for line in inputFile:
        x,r,c = [int(n) for n in line.strip().split()]
        inputData.append({'x':x, 'r':r, 'c':c})

def ifRichardWillWin(x, r, c):
    # if X > 7 : Richard choose an omino with a hole in the middle
    if x >= 7:
        return True

    # if X > max(R,C) : Richard choose a long omino that doesnt fit in the grid
    if x > r and x > c:
        return True

    # if (R*C) % X != 0 : grid is not suitable for X-omino
    if (r*c) % x > 0:
        return True

    # if X >= 2*(min(R,C)+1) - 1 : Richard can find an omino that larger than the smaller size of the grid, regardless of how u turn the omino
    # equivalent to min(R,C) <= 2 and X >= 5
    if x >= (2*(min(r,c)+1) - 1):
        return True

    # if X >= (2*min(R,C) -1) : split the grid into >= 3 parts
    if x >= (2*min(r,c) - 1):
        if x == 4 or x == 6:
            return True
        if x == 5 and (r*c)/x < 3:
            return True

    return False


inputData = []
readInput(sys.argv[1])

for i in range(len(inputData)):
    data = inputData[i]
    winner = 'RICHARD' if ifRichardWillWin(data['x'],data['r'],data['c']) else 'GABRIEL'
    print "Case #{0}: {1}".format(i+1, winner)