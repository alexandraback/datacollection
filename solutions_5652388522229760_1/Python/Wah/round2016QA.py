
class TestCase:
    def __init__(self, caseIndex):
        self.caseIndex = caseIndex

    def parseInput(self):
        self.N = int(raw_input())
        self.lastNumber = 0
        self.digits = []

    def run(self):
        if self.N != 0:
            count = 0
            while count < 72:
                count += 1
                self.lastNumber = self.N * count
                for digit in str(self.lastNumber):
                    if digit not in self.digits:
                        self.digits.append(digit)
                if len(self.digits) == 10:
                    break

    def generateOutput(self):
        if self.lastNumber != 0:
            print "Case #%d: %d" % (self.caseIndex, self.lastNumber)
        else:
            print "Case #%d: INSOMNIA" % (self.caseIndex)

for caseIndex in range(1, int(raw_input()) + 1):
    testCase = TestCase(caseIndex)
    testCase.parseInput()
    testCase.run()
    testCase.generateOutput()