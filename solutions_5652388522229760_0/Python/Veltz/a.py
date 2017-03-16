'''
Created on May 7, 2011

@author: doronv
'''
# import section
import sys

from certifi import __main__

def a(Input, Output):
    # read number of cases
    T = int(Input.readline())
    
    # iterate on all cases
    for t in range(T):
        # read N
        N = int(Input.readline())

        if (N == 0):
            outStr = "INSOMNIA"
        else:
            digits = [0,1,2,3,4,5,6,7,8,9];

            M = 0
            # while we have remaining digits
            while digits:
                # check digits in M (=x*N)
                M += N
                for c in str(M) :
                    d = ord(c) - ord('0')
                    if d in digits :
                        digits.remove(d)
            outStr = str(M)
    
        # Output case result
        outputLine = 'Case #' + str(t + 1) + ': ' + outStr + '\n'
        Output.write(outputLine)
    
    # close Input and Output 
    Input.close()
    Output.close()
    
if __name__ == '__main__':
    inputFile = open(sys.argv[1], 'r')
    outputFile = open(sys.argv[2], 'w')
    a(inputFile, outputFile)