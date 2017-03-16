__author__ = 'caseyvu'

import sys

def readInput(fileName):
    global inputData

    inputFile = open(fileName)

    inputFile.readline() # number of test cases
    for line in inputFile:
        _, shyness = line.strip().split(' ')
        shynessList = [int(d) for d in shyness]
        inputData.append(shynessList)

def findNumberOfFriendsRequired(shynessList):
    standingPpl = 0
    friendReq = 0
    for shyLevel in range(len(shynessList)):
        if standingPpl < shyLevel:
            additionalFriends = shyLevel - standingPpl
            friendReq = friendReq + additionalFriends
            standingPpl = standingPpl + shynessList[shyLevel] + additionalFriends
        else:
            standingPpl = standingPpl + shynessList[shyLevel]
    return friendReq

if len(sys.argv) < 2:
    print "Usage: {0} <inputFile>".format(sys.argv[0])
    sys.exit(0)

inputData = []
readInput(sys.argv[1])

for i in range(len(inputData)):
    req = findNumberOfFriendsRequired(inputData[i])
    print "Case #{0}: {1}".format(i+1, req)