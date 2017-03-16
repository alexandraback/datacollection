def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [None for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        N  = int(inputfile.readline())
        lines = [None]*(2*N-1)
        for j in range(2*N-1):
            tmp = inputfile.readline().split()
            lines[j] = [int(x) for x in tmp]
        cases[i] = lines
    inputfile.close()
    return cases

cases = dataParser('test.txt')
outputFile = open('out.txt','w')
for i in range(len(cases)):
    x = cases[i]
    cnt = dict()
    output = []
    for j in range(len(x)):
        for k in range(len(x[j])):
            if x[j][k] in cnt:
                cnt[x[j][k]]+=1
            else:
                cnt[x[j][k]] = 1
    for (key,value) in cnt.iteritems():
        if value%2==1:
            output.append(key)
    assert len(output)==len(x[0])
    output = sorted(output)
    outputFile.write('Case #' + str(i + 1) + ':')
    for k in range(len(output)):
        outputFile.write(' '+str(output[k]))
    outputFile.write('\n')
outputFile.close()
