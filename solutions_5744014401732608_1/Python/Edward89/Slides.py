import math
def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [None for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        tmp = inputfile.readline().split();
        cases[i] = [int(x) for x in tmp]
    inputfile.close()
    return cases

cases = dataParser('test.in')
outputFile = open('out.txt','w')
print cases
for i in range(len(cases)):
    B = cases[i][0]
    M = cases[i][1]
    if M>math.pow(2,B-2):
        outputFile.write('Case #' + str(i + 1) + ': IMPOSSIBLE\n')
    else:
        outputFile.write('Case #' + str(i + 1) + ': POSSIBLE\n')
        for k in range(B-1):
            for j in range(k):
                outputFile.write('0')
            outputFile.write('0')
            for j in range(k+1,B-1):
                outputFile.write('1')
            if k==0:
                outputFile.write('1')
            else:
                if (M-1)&(1<<(k-1))>0:
                    outputFile.write('1')
                else:
                    outputFile.write('0')
            outputFile.write('\n')
        for j in range(B):
            outputFile.write('0')
        outputFile.write('\n')
outputFile.close()
