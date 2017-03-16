import fileinput

# input formatting
class FileWrapper:

    def __init__(self, file=None, filename=None):
        if filename:
            self.file = open(filename)
        elif file:
            self.file = file
        else:
            raise Exception('miss input file')
    
    def getInt(self):
        return int(self.file.readline())
    
    def getInts(self):
        return [int(z) for z in self.file.readline().split()]
    
    def getFloat(self):
        return float(self.file.readline())
    
    def getFloats(self):
        return [float(z) for z in self.file.readline().split()]
    
    def getWords(self):
        return self.file.readline().split()
    
    def readline(self):
        return self.file.readline().strip()
    
    def close(self):
        self.file.close


# formatted printing
caseNum = 1


def printCase(result, resetNum=None):
    global caseNum

    if resetNum:
        caseNum = resetNum 

    if isinstance(result, list):
        print "Case #{0}:".format(caseNum)
        for line in result:
            print line
    else:
        print "Case #{0}: {1}".format(caseNum, result)

    caseNum += 1
    
