import sys

class MineMap:
    def __init__(self, sharedMap ,R ,C ):
        self.map = sharedMap
        self.R = R
        self.C = C
    def fillLastRow( self ):
        for i in range (0, self.C):
            self.map[ self.R - 1 ][ i ] = 1

    def fillLastCol( self ):
        for i in range (0, self.R):
            self.map[ i ][ self.C - 1 ] = 1
            
    
    def setMines( self, M ):
        if M == 0:
            self.setClickPoint( 0, 0)
            return self.printMap()
        if self.R * self.C == 4:
            if M == 0:
                self.setClickPoint( 0, 0 )
                return self.printMap()
            elif M == 1 or M == 2:
                return "Impossible\n"
            else:
                self.setMinePoint( 0, 1 )
                self.setMinePoint( 1, 0 )
                self.setMinePoint( 1, 1 )
                self.setClickPoint( 0, 0 )
                return self.printMap()

        # reduce it if you can
        if min(self.R, self.C) <= M:
            if (self.R >= self.C):
                self.fillLastRow()
                mineMap = MineMap( self.map, self.R - 1, self.C )
            else:
                self.fillLastCol()
                mineMap = MineMap( self.map, self.R, self.C - 1 )

            return mineMap.setMines( M - min(self.R, self.C) )
        
        else:
            # minUse always bigger than M.
            minUse = min(self.R, self.C)
            if minUse == 2 and M == 1:
                return "Impossible\n"
            
            numToUse = max(self.R, self.C)
            if numToUse - 2 < M:
                if M < (self.R-2)*(self.C-2):
                    for i in range( 0, M ):
                        self.setMinePoint( self.R - (i / (self.C-2)) - 1, self.C - (i % (self.C-2)) - 1 )
                    self.setClickPoint( 0, 0 )
                    return self.printMap()
                return "Impossible\n"
            else:
                if ( self.R >= self.C ):
                    for i in range( 0, M ):
                        self.setMinePoint( self.R - i - 1, self.C - 1 )
                    self.setClickPoint( 0, 0 )
                    return self.printMap()
                else:
                    for i in range( 0, M ):
                        self.setMinePoint( self.R - 1, self.C - i - 1 )
                        
                    self.setClickPoint( 0, 0 )
                    return self.printMap()

    def setMinePoint( self, x, y ):
        self.map[x][y] = 1

    def setClickPoint( self, x, y ):
        self.map[x][y] = 2

    def printMap( self ):
        ret = ""
        for row in self.map:
            for col in row:
                if col == 1:
                    ret += "*"
                elif col == 0:
                    ret += "."
                else:
                    ret += "c"
            ret +="\n"

        return ret

class Problem:
    def __init__(self, inputFileName, outputFileName):
        self.inputFile = open( inputFileName, "r" )
        self.outputFile = open( outputFileName, "w" )
        self.numSamples = int(self.inputFile.readline().replace("\n",""))
        self.resultList = []
        self.outputLines= []
    def printResult( self ):
        for i in range(0, self.numSamples):
            line = "Case #%d:\n%s"%(i+1,self.resultList[i])
            print line
            self.outputLines.append( line )

    def saveResult( self ):
        for line in self.outputLines:
            self.outputFile.write( line+"" )

    def getResult( self, R, C, M):

        sharedMap = []
        for rowNum in range(0, R):
            sharedMap.append( [0]*C )
            
        mineMap = MineMap( sharedMap, R, C )

        if R == 1:
            for i in range(0, M):
                mineMap.setMinePoint( 0, C - i - 1 )
            mineMap.setClickPoint( 0, 0 )
            return mineMap.printMap()

        if C == 1:
            for i in range(0, M):
                mineMap.setMinePoint( R - i - 1, 0 )
            mineMap.setClickPoint( 0, 0 )
            return mineMap.printMap()
                
        return mineMap.setMines( M )
        
    def solve( self ):
        for i in range(0, self.numSamples):
            (R,C,M) = self.readSample()
            result = self.getResult( R,C,M )
            self.resultList.append( result )
        
        self.printResult()
        #self.testSampleOutput()
        self.saveResult()
        
    def readSample( self ):
        sample = self.inputFile.readline()
        indata = sample.split(' ')
        R = int(indata[0])
        C = int(indata[1])
        M = int(indata[2])
        return (R,C,M)

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
