
class TestCase:
    def __init__(self, caseIndex):
        self.caseIndex = caseIndex

    def parseInput(self):
        self.S = raw_input()
        self.minCount = 0

    def run(self):
        if self.S.find("-") == -1:
            self.minCount = 0
        elif self.S.find("+") == -1:
            self.minCount = 1
        else:
            while self.S.find("++") > -1:
                self.S = self.S.replace("++", "+")
            while self.S.find("--") > -1:
                self.S = self.S.replace("--", "-")
            lastIndex = self.S.find("-")
            while self.S.find("-", lastIndex + 1) != -1:
                lastIndex = self.S.find("-", lastIndex + 1)
            self.minCount = lastIndex + 1

    def generateOutput(self):
        print "Case #%d: %d" % (self.caseIndex,self.minCount)

for caseIndex in range(1, int(raw_input()) + 1):
    testCase = TestCase(caseIndex)
    testCase.parseInput()
    testCase.run()
    testCase.generateOutput()
