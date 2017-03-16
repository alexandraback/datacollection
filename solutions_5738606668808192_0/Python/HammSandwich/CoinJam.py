import os

def main():
    #generate()
    h = CodeJamHelper("C-small-attempt0")

    n = h.nextInt()

    for x in range(n):
        l = h.nextLineOfInts()
        h.output(process(l[0], l[1]))


def process(n, j):
    answers = []
    base = 2**(n-1) + 1
    endpoint = 2**n
    while len(answers) < j and base < endpoint:
        strBase = bin(base).split("b")[1]
        potential = [];
        x = 2
        while x <= 10 and False not in potential:
            potential.append(findDivisor(x, strBase))
            x = x + 1
        if(False not in potential):
            potential.reverse()
            potential.append(strBase)
            potential.reverse()
            answers.append(potential)
        base = base + 2
    return formatOutput(answers)

def findDivisor(x, strBase):
    intBase = int(strBase, x)
    i = 2
    #the space of all numbers is much much larger than the size of the expected output
    #so much so that it doesn't matter if we give up on a bunch at 50 to avoid
    #processing forever!
    while i < 50 and i < intBase/2:
        if intBase % i == 0:
            return i
        i = i +1
    return False

def formatOutput(answers):
    strLines = []
    for line in answers:
        strLine = [str(x) for x in line]
        strLines.append( " ".join(strLine))
    return "\n".join(strLines)


    # intBase = int(strBase, x)



class CodeJamHelper:
    """Helper for the common things I do during Google Code Jam"""
    def __init__(self, baseFileName):
        self.ensureDirectory("./output")
        self.inFile = open("./input/" + baseFileName + ".in", "r")
        self.outFile = open("./output/" + baseFileName + ".out", "w")
        self.caseNum = 1

    def ensureDirectory(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

    def output(self, value):
        print "Case #" + str(self.caseNum) + ": " + str(value)
        self.outFile.write( "Case #" + str(self.caseNum) + ": " + str(value) + "\n")
        self.caseNum = self.caseNum + 1

    def nextLine(self):
        return self.inFile.readline()[:-1] #strip the new line, it's bad

    def nextInt(self):
        return int(self.nextLine())

    def nextLineOfInts(self, delim=" "):
        line = self.nextLine()
        return [int(x) for x in line.split(delim)]

    def nextLineOfFloats(self, delim=" "):
        line = self.nextLine()
        return [float(x) for x in line.split(delim)]

    def nextDelimitedLine(self, delim=" "):
        return self.nextLine().split(delim)

    def nextDelimitedMatrix(self, x, y, delim=" "):
        matrix = []
        for _ in range(len(x)):
            line = self.nextLine()
            line = [item for item in line.split(delim)]
            if(len(line) != y):
                print "problem, matrix does not match specified dimensions"
            matrix.append(line)
        return matrix

    def nextCharMatrix(self, x, y):
        matrix = []
        for _ in range(len(x)):
            line = self.nextLine()
            line = [item for item in line]
            if(len(line) != y):
                print "problem, matrix does not match specified dimensions"
            matrix.append(line)
        return matrix

    def getStringMatrix(self, matrix, space=True):
        out = ""
        for line in matrix:
            out = out + "\n"
            for item in line:
                out = out + str(item)
                if(space):
                    out = out + " "
            if(space):
                out = out[:-1]
        return out

if __name__ == "__main__":
    main()
