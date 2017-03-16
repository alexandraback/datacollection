import sys


class Problem:
    def __init__(self, inputFileName, outputFileName):
        self.inputFile = open( inputFileName, "r" )
        self.outputFile = open( outputFileName, "w" )
        self.numSamples = int(self.inputFile.readline().replace("\n",""))
        self.resultList = []
        self.outputLines= []
    def printResult( self ):
        for i in range(0, self.numSamples):
            line = "Case #%d: %s"%(i+1,self.resultList[i])
            print line
            self.outputLines.append( line )

    def saveResult( self ):
        for line in self.outputLines:
            self.outputFile.write( line+"\n" )

    def getResult( self, C, F, X ):
        timeSpent = float(0)
        currentSpeed = float(2)

        while( C * ( currentSpeed + F ) - X * F < 0):
            timeSpent += ( C / currentSpeed )
            currentSpeed += F

        timeSpent += X / currentSpeed
        return "%.7f"%(timeSpent,)
        
    def solve( self ):
        for i in range(0, self.numSamples):
            (C,F,X) = self.readSample()
            result = self.getResult( C,F,X )
            self.resultList.append( result )
        
        self.printResult()
        #self.testSampleOutput()
        self.saveResult()
        
    def readSample( self ):
        sample = self.inputFile.readline()
        indata = sample.split(' ')
        C = float(indata[0])
        F = float(indata[1])
        X = float(indata[2])
        return (C,F,X)

    def testSampleOutput( self ):
        sampleOutputFile = open( "output_sample.txt" )
        sampleResult = []

        result = True
        idx = 0
        print " * testing..."
        for line in sampleOutputFile:
            line = line.replace("\n", "")
            print line
            print self.outputLines[idx]
            result &= (line == self.outputLines[ idx ])
            idx += 1

        print result
    
def main():
    problem = Problem( sys.argv[1], "output.txt" )
    problem.solve()
    

    

if __name__ == "__main__":
    main()
