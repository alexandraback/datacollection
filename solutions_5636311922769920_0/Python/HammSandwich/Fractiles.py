import os
import math

def main():
    #generate()
    h = CodeJamHelper("D-small-attempt1")

    n = h.nextInt()

    for x in range(n):
        l = h.nextLineOfInts()
        h.output(process(l[0], l[1], l[2]))


def process(kTiles, complexity, students):
    # for every layer of complexity I can check another of the original tiles at once
    minStudents = math.ceil((1.0*kTiles)/complexity)

    if minStudents > students:
        return "IMPOSSIBLE"

    # now we know we have enough students,allocate them
    output = []
    total = 0
    for i in range(kTiles):
        #total = total + ((1.0*i)/kTiles)*((kTiles ** complexity) / kTiles ** (i % complexity))
        exponent = complexity - (i % complexity)
        total = total + (i) * (kTiles ** (exponent-1))
        if (i+1) % complexity == 0:
            output.append(str(long(total+1)))
            total = 0
    if kTiles % complexity != 0:
        output.append(str(long(total+1)))
    return " ".join(output)

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
