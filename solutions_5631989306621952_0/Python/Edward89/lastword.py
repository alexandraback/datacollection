def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [0 for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        cases[i] = inputfile.readline()
    inputfile.close()
    return cases

cases = dataParser('test.txt')
outputFile = open('out.txt','w')
for i in range(len(cases)):
    x = cases[i]
    output = x[0]
    for j in range(1,len(x)):
        if x[j]<output[0]:
            output+=x[j]
        else:
            output = x[j]+output
    print output
    outputFile.write('Case #' + str(i + 1) + ': ' + output)
outputFile.close()

