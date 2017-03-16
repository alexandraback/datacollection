
class TestCase:
    def __init__(self, caseIndex):
        self.caseIndex = caseIndex

    def parseInput(self):
        self.K, self.C, self.S = [int(x) for x in raw_input().split(" ")]

    def run(self):
        pass

    def generateOutput(self):
        print "Case #%d: %s" % (self.caseIndex, " ".join([str(x + 1) for x in range(self.S)]))

for caseIndex in range(1, int(raw_input()) + 1):
    testCase = TestCase(caseIndex)
    testCase.parseInput()
    testCase.run()
    testCase.generateOutput()
