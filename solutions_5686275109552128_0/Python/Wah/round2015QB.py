
import math
testCaseIndex = 0

def requiredStep(pcs):
    maxPc = max(pcs)

    maxStep = maxPc


#print 'max step for ' , pcs, ' is ', maxStep
    if maxStep <= 3:
        return maxStep

    pcs.remove(maxPc)
    newPc1 = int(math.floor(float(maxPc) / 2))
    newPc2 = int(math.ceil(float(maxPc) / 2))
    pcs.append(newPc1)
    pcs.append(newPc2)
    minStep = requiredStep(pcs) + 1
#   print 'split step for ' , pcs, ' is ', minStep
    pcs.remove(newPc1)
    pcs.remove(newPc2)
    pcs.append(maxPc)


    pcs.remove(maxPc)
    newPc1 = 3
    newPc2 = maxPc - 3
    pcs.append(newPc1)
    pcs.append(newPc2)
    minStep2 = requiredStep(pcs) + 1
    #   print 'split step for ' , pcs, ' is ', minStep
    pcs.remove(newPc1)
    pcs.remove(newPc2)
    pcs.append(maxPc)

    if minStep2 < minStep:
        return minStep2
    elif minStep < maxStep:
        #print 'split step return'
        return minStep
    else:
        #print 'normal step return'
        return maxStep

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.D = int(raw_input())
        self.PCS = [int(x) for x in raw_input().split(" ")]



    def generateOutput(self):
        print "Case #%d: %s" % (testCaseIndex, requiredStep(self.PCS))

def execTestCase():

    testcases = int(raw_input())
    for i in range(testcases):
        #print 'Case', i + 1
        testCase = TestCase()

        testCase.parseInput()
        #print testCase.D, testCase.PCS
        testCase.generateOutput()


execTestCase()