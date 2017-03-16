import sys

class InputFile:
    cases = 0
    filename = ''
    caseLength = 0
    lines = []

    def __init__(self, filename, caseLength):
        self.filename = filename
        self.caseLength = caseLength

    def read(self):
        with open(self.filename, 'r') as f:
            self.lines = f.readlines()
        self.lines = [line.strip() for line in self.lines]
        self.cases = int(self.lines[0])

    def getCases(self):
        return self.cases

    def getCase(self, index):
        caseLines = []
        startOffset = (index-1)*self.caseLength + 1
        endOffset = index*self.caseLength + 1
        for i in range(startOffset, endOffset):
            caseLines.append(self.lines[i])
        return caseLines


class CaseSolver:
    def __init__(self, caseNumber, caseInfo):
        self.number = caseNumber
        self.params = caseInfo

    def solve(self):
        result = ""
        N = int(self.params[0])
        BFF = [int(x) for x in self.params[1].split()]
        max_length = 0
        for n in range(0, N):
            circle = []
            i = n
            while not i in circle:
                circle.append(i)
                i = BFF[i]-1

            startIndexes = []
            endIndexes = []
            foundPrevious = False
            foundNext = False
            for i in range(0, len(BFF)):
                if not foundPrevious and (circle[0]+1) == BFF[i] and not i in circle:
                    circle.insert(0, i)
                    foundPrevious = True
                if not foundNext and (circle[-1]+1) == BFF[i] and not i in circle:
                    circle.append(i)
                    foundNext = True
            if len(circle) > max_length:
                solution = circle
                max_length = len(circle)

        print solution
        return "Case #" + str(self.number) + ": " + str(max_length)


if __name__ == '__main__':
    if len(sys.argv) == 2:
        # 1. Update the number of lines per case
        linesPerCase = 2
        input_file = InputFile(sys.argv[1], linesPerCase);
        input_file.read()
        for i in range(1, input_file.getCases() + 1):
            print CaseSolver(i, input_file.getCase(i)).solve()
    else:
        usage = "Usage :"
        usage = usage + sys.argv[0]
        usage = usage + " <input_file>"
        print usage
