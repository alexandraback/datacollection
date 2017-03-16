import sys


class Naomi:
    def __init__( self, blocks, kenBlocks ):
        self.blocks = list(blocks)
        self.kens = list(kenBlocks)
        self.virtualKen = Ken( kenBlocks )

    def removeKensBlock( self, myDeceivedValue ):
        theValue = self.virtualKen.playTurn( myDeceivedValue )
        self.kens.remove( theValue )
        
    def playTurn( self ):
        myLowest = self.blocks[0]
        myHighest = self.blocks[ len(self.blocks) - 1 ]
        hisLowest = self.kens[0]
        hisHighest = self.kens[ len(self.kens) - 1 ]

        if( len( self.blocks ) == 1 ):
            theValue = self.blocks.pop(0)
            self.removeKensBlock( theValue )
            return (theValue, theValue)
            
        if myLowest < hisLowest:
            hisSecondHighest = self.kens[ len(self.kens) - 2 ]

            theDeceivedWeight = hisSecondHighest + (hisHighest - hisSecondHighest)/2
            theActualWeight = self.blocks.pop(0) # remove the lowest block

            self.removeKensBlock( theDeceivedWeight )
            return (theActualWeight, theDeceivedWeight)

        else:
            theActualWeight = self.blocks.pop(0)
            theDeceivedWeight = hisHighest + ( 1 - hisHighest ) / 2
            self.removeKensBlock( theDeceivedWeight )
            return (theActualWeight, theDeceivedWeight)
            
'''
        if( myLowest > hisHighest or len(self.blocks) == 1 ):
            # be honest
            self.kens.pop(0) # ken will destroy his lowest block.
            theBlock = self.blocks.pop(0)
            return (theBlock, theBlock)
'''

        

class GoodNaomi:
    def __init__( self, blocks ):
        self.blocks = list(blocks)

    def playTurn( self ):
        return self.blocks.pop(0)

class Ken:
    def __init__( self, blocks ):
        self.expectWin = False
        self.blocks = list(blocks)

    def playTurn( self, naomiWeight ):
        for item in self.blocks:
            if item > naomiWeight:
                self.blocks.remove( item )
                self.expectWin = True
                
                return item

        self.expectWin = False
        # if he cannot win, just give up and destroy least weight block
        return self.blocks.pop(0)

    def isHeNoticed( self, isKenWin ):
        return isKenWin <> self.expectWin

class Problem:
    def __init__(self, inputFileName, outputFileName):
        self.inputFile = open( inputFileName, "r" )
        self.outputFile = open( outputFileName, "w" )
        self.numSamples = int(self.inputFile.readline().replace("\n",""))
        self.resultList = []
        self.outputLines= []
    def printResult( self ):
        for i in range(0, self.numSamples):
            naomi, goodnaomi = self.resultList[i]
            line = "Case #%d: %d %d"%(i+1, naomi, goodnaomi)
            print line
            self.outputLines.append( line )

    def saveResult( self ):
        for line in self.outputLines:
            self.outputFile.write( line+"\n" )

    def getResult( self, N, Naomis, Kens ):
        naomiBlocks = []
        kenBlocks = []
        for i in range(0, N):
            naomiBlocks.append( float( Naomis[i] ) )
            kenBlocks.append( float( Kens[i] ) )

        naomiBlocks.sort()
        kenBlocks.sort()
        print naomiBlocks
        print kenBlocks
        naomi = Naomi( naomiBlocks, kenBlocks )
        ken = Ken( kenBlocks )


        # Deceived
        naomiPoint = 0
        kenPoint = 0
        for i in range(0, N):
            (naomiChoose, naomiTold) = naomi.playTurn()
            print "Naomi: ", naomiChoose," ,Told: ",naomiTold
            kenChoose = ken.playTurn( naomiTold )
            print "Ken: ", kenChoose
            if( naomiChoose > kenChoose ):
                naomiPoint += 1
            elif( kenChoose > naomiChoose ):
                kenPoint += 1
            else:
                print "This case is impossible."
                exit(-1)

            if ( ken.isHeNoticed( kenChoose > naomiChoose ) ):
                print "Ken Noticed."
                exit(-1)

        # Not Deceived
        goodnaomi = GoodNaomi( naomiBlocks )
        goodken = Ken( kenBlocks )
        goodNaomiPoint = 0
        goodKenPoint = 0
        for i in range(0, N):
            naomiChoose = goodnaomi.playTurn()
            print "Naomi: ", naomiChoose
            kenChoose = goodken.playTurn( naomiChoose )
            print "Ken: ", kenChoose
            if( naomiChoose > kenChoose ):
                goodNaomiPoint += 1
            elif( kenChoose > naomiChoose ):
                goodKenPoint += 1
            else:
                print "This case is impossible."
                exit(-1)

        return (naomiPoint, goodNaomiPoint)

        
    def solve( self ):
        for i in range(0, self.numSamples):
            ( N, Naomis, Kens ) = self.readSample()
            result = self.getResult( N, Naomis, Kens )
            self.resultList.append( result )
        
        self.printResult()
        #self.testSampleOutput()
        self.saveResult()
        
    def readSample( self ):
        N = int(self.inputFile.readline())

        naomiBlocks = self.inputFile.readline().replace("\n","").split(" ")
        kenBlocks = self.inputFile.readline().replace("\n","").split(" ")
        
        return ( N, naomiBlocks, kenBlocks )

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
