
import math
testCaseIndex = 0


def requiredStep(pcs):
    maxStep = max(pcs)
    minStep = max(pcs)

    for normalStep in range(1, maxStep + 1):
        splitMinStep = normalStep

        for pc in pcs:
            splitMinStep += int (math.floor((pc - 1) / normalStep))
            if splitMinStep > maxStep:
                break
        if splitMinStep < minStep:
            minStep = splitMinStep


    return minStep

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.D = int(raw_input())
        self.PCS = [int(x) for x in raw_input().split(" ")]



    def generateOutput(self):

        print "Case #%d: %s" % (testCaseIndex, requiredStep(self.PCS))

import time

def execTestCase():
    starttime = time.time()
    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()

        testCase.parseInput()
        testCase.generateOutput()


execTestCase()