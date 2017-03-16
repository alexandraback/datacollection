import os

class CodeJamHelper:
    """Helper for the common things I do during Google Code Jam"""
    def __init__(self, baseFileName):
        self.ensureDirectory("./output")
        self.inFile = open("C:\Users\Peter\Downloads\\" + baseFileName + ".in", "r")
        self.outFile = open("C:\Users\Peter\Desktop\cj2014\\" +baseFileName + ".out", "w")
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