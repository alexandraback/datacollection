
testCaseIndex = 0

def generateBoard(R, C):
    datas = []
    for rn in range(R):
        datas.append([])
        for cn in range(C):
            datas[rn].append(0)
    return datas

def printBoard(datas):
    for rn in range(len(datas)):
        for cn in range(len(datas[rn])):
            print datas[rn][cn],
        print
    print

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.X, self.R, self.C = raw_input().split(" ")
        self.X = int(self.X)
        self.R = int(self.R)
        self.C = int(self.C)

    def generateOutput(self):
        datas = generateBoard(self.R, self.C)
        #printBoard(datas)

        if self.X == 1:
            self.winner = "GABRIEL"
        elif self.X > self.R and self.X > self.C:
            self.winner = "RICHARD"
        elif self.X == 2:
            if (self.R * self.C) % 2 == 0:
                self.winner = "GABRIEL"
            else:
                self.winner = "RICHARD"
        elif self.X == 3:
            if (self.R * self.C) % 3 == 0:
                if self.R == 1 or self.C == 1:
                    self.winner = "RICHARD"
                else:
                    self.winner = "GABRIEL"
            else:
                self.winner = "RICHARD"
        elif self.X == 4:
            if self.R == 1 or self.C == 1:
                self.winner = "RICHARD"
            elif self.R == 2 or self.C == 2:
                self.winner = "RICHARD"
            else:
                self.winner = "GABRIEL"
        else:
            self.winner = "UNKNOWN"

        print "Case #%d: %s" % (testCaseIndex, self.winner)
        
def execTestCase():
    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()
        testCase.parseInput()
        #print testCase.X, testCase.R, "x", testCase.C
        testCase.generateOutput()


execTestCase()
