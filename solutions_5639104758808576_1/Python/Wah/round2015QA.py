
testCaseIndex = 0

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.SMAX, self.SCOUNTS = raw_input().split(" ")
        self.SMAX = int(self.SMAX)

    def generateOutput(self):

        currentStand = 0
        requiredStand = 0
        SLEVEL = 0
        for count in range(self.SMAX):
            currentStand += int(self.SCOUNTS[count])
            if currentStand < SLEVEL + 1:
                requiredStand += SLEVEL + 1 - currentStand
                currentStand = SLEVEL + 1
            SLEVEL += 1

        print "Case #%d: %d" % (testCaseIndex, requiredStand)

def execTestCase():
    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()
        testCase.parseInput()
        testCase.generateOutput()

execTestCase()
