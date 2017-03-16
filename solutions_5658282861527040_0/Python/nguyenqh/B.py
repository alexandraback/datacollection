import math

##inputFile = open('B-sample.in','r')
##outputFile = open('B-sample.ou','w')
inputFile = open('B-small-attempt0.in','r')
outputFile = open('B-small-attempt0.ou','w')
##inputFile = open('A-large-practice.in','r')
##outputFile = open('A-large-practice.ou','w')
numTest = int(inputFile.readline())
for testid in range(1,numTest+1):
    A,B,K = [int(s) for s in inputFile.readline().split()]
##    print(A,B,K)
    count = 0
    for x in range(A):
        for y in range(B):
            if x&y<K:
                count = count+1
                
    print('Case #',testid,': ',count, sep='',file=outputFile)


outputFile.close()
    
        
