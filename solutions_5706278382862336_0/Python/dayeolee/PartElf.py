import sys
import math
from decimal import *

def generation( num, start ):
    print num, start
    ret = 0
    while ( num < start and start > 0 ):
        start /= 2
        ret += 1

    return ret + 1

def gcd(a, b):
    while( b!=0 ):
        tmp = a % b
        a = b
        b = tmp
    return abs(a)

def reduce( P, Q ):

    GCD = gcd(P, Q)

    Pn = P/GCD
    Qn = Q/GCD

    return ( Pn, Qn )

class Problem:
    def __init__(self, inputFileName, outputFileName):
        self.inputFile = open( inputFileName, "r" )
        self.outputFile = open( outputFileName, "w" )
        self.numSamples = int(self.inputFile.readline().replace("\n",""))
        self.resultList = []
        self.outputLines= []
    def printResult( self ):
        for i in range(0, self.numSamples):
            res = self.resultList[i]
            line = "Case #%d: %s"%(i+1,res )
            print line
            self.outputLines.append( line )

    def saveResult( self ):
        for line in self.outputLines:
            self.outputFile.write( line+"\n" )

    def getResult( self, P, Q ):
        (P, Q) = reduce(P, Q)
        

        if not ( Q > 0 and ( (Q & (Q-1)) == 0 ) ):
            return "impossible"

        print P,"/",Q

        N = int( math.log( Q, 2 ) )
        
        return generation( P, Q/2 )

        
    def solve( self ):
        for i in range(0, self.numSamples):
            ( P, Q ) = self.readSample()
            result = self.getResult( P, Q )
            self.resultList.append( result )
        
        self.printResult()
        #self.testSampleOutput()
        self.saveResult()
        
    def readSample( self ):
        line = self.inputFile.readline()
        vals = line.split( "/" )
        P = int(vals[0])
        Q = int(vals[1])
        
        return ( P, Q )

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
    getcontext().prec = 200
    problem = Problem( sys.argv[1], "output.txt" )
    problem.solve()
    

    

if __name__ == "__main__":
    main()
