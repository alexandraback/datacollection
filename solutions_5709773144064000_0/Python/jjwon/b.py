#!/usr/bin/env python
#
# Problem: Cookie Clicker
# Language: Python
# Author: jjwon
# Usage: python thisfile.py < input.in > output.out


import fileinput

def calcTime(testCase):
    farmPrice, farmRate, goal = testCase[0], testCase[1], testCase[2]
    currentRate = 2
    timeThusFar = 0
    while True:
        if isItWorthBuying(farmPrice, currentRate, farmRate, goal):
            timeThusFar += farmPrice/currentRate
            currentRate += farmRate
        else:
            timeThusFar += goal/currentRate
            break
    return timeThusFar
"""
Given that we have 0 cookies right now (cause we just bought a farm)
"""
def isItWorthBuying(farmPrice, currentRate, farmRate, goal):
    newFarmTime = farmPrice/currentRate
    totalTimeOld = goal/currentRate
    totalTimeNew = newFarmTime + goal/(currentRate+farmRate)
    return totalTimeNew < totalTimeOld

def main():
    numTestCase = 1
    gotNumOfTestCases = False
    testCases = []
    for line in fileinput.input():
        if not gotNumOfTestCases:
            numOfTestCases = int(line)
            gotNumOfTestCases = True
        else:
            testCases.append(line.split())
            # print(testCases)
            for i in range(3):
                testCases[-1][i] = float(testCases[-1][i]) # converts numbers to floats
    for i in range(len(testCases)):
        print "Case #%d: %0.7f" % (i+1,calcTime(testCases[i]))



if __name__ == "__main__":
    main()