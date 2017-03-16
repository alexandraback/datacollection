import sys
import math

if __name__ == "__main__":
    f = open( "input_small.txt" )
    g = open( "output_small.txt","w" )
    #g = sys.stdout

    numcases = f.readline()

    caseI = 1
    line = f.readline()
    while line != "":
        numtyped,numtotal = [ int(x) for x in line.split() ]
        probs = [ float(x) for x in f.readline().split() ]

        probcorrect = [0]*len(probs)
        i = 1.0
        index = 0
        for x in probs:
            i = i * x
            probcorrect[index] = i
            index += 1

        restofkeys = numtotal - numtyped
        #numkeysCarryon = restofkeys + (1-probcorrect[-1])*(numtotal+1) + 1
        numkeysGiveup = 2 + numtotal


        pCorrect = probcorrect[::-1]
        
        backspace = [0]*len(pCorrect)
        for i in range(len(backspace) ):
            backspace[i] = (i+1+restofkeys+i) + (1-pCorrect[i])*(numtotal+1) 
        backspace.append( 1+numtotal+numtyped )
            
        output = min( [min(backspace),numkeysGiveup] )

        print backspace,numkeysGiveup
        
        g.write( "Case #%s: %.6f\n"%(caseI,output) )
        caseI += 1
        line = f.readline()
    f.close()
    g.close()
