filein = open('read.txt')
fileout = open('write.txt', 'w')

a = filein.readlines()
numTest = int(a.pop(0))

for Z in range(0, numTest):
    scores = a.pop(0).split()
    listOfScores = []
    numScores = int(scores.pop(0))
    for i in range(0, numScores):
        listOfScores.append(int(scores.pop(0)))
    X = float(sum(listOfScores))
    listOfPerc = []
    for i in range(0, numScores):
        temp = 2.0/numScores
        temp2 = listOfScores[i]/X
        listOfPerc.append(temp-temp2)
    myString = 'Case #%d:' %(Z+1)
    
    hasNeg = False
    isNeg = []
    for i in listOfPerc:
        if i < 0:
            hasNeg = True
            isNeg.append(1)
        else:
            isNeg.append(0)
                    
    while hasNeg:
        Xtemp = 0.0
        numPos = 0
        for i in range(0, numScores):
            if isNeg[i] == 0:
                Xtemp += listOfScores[i]
                numPos += 1
            listOfPerc[i] = 0
        for i in range(0, numScores):
            if isNeg[i] == 1:
                continue
            temp = Xtemp + X
            temp = temp/numPos
            temp -= listOfScores[i]
            temp = temp/X
            listOfPerc[i] = temp
        hasNeg = False
        for i in listOfPerc:
            if i < 0:
                hasNeg = True
        if hasNeg:
            for i in range(0, numScores):
                if listOfPerc[i] < 0:
                    isNeg[i] == 1
        if not hasNeg:
            break


        print listOfPerc


    
    for i in range(0, numScores):
        if isNeg[i] == 1:
            myString += ' 0.0'
        else:
            myString += ' %.5f' %(listOfPerc[i]*100)
    myString += '\n'
    fileout.write(myString)

filein.close()
fileout.close()
    
    
