inputFileName = "C:\\Users\\t8081591\\Desktop\\C-small-attempt0.in"
outputFileName = "C:\\Users\\t8081591\\Desktop\\C-small-attempt0.out"

def readFileIntoList(fileName):
    with open(fileName) as f:
        content = f.readlines()
        contentFixed = [c.split() for c in content[1:]]
        T = int(content[0])
    return (T,contentFixed)

def Technobabble(inputList):
    n = int(inputList[0])
    firstSet = set()
    secondSet = set()

    for l in inputList[1:]:
        firstSet.add(l[0])
        secondSet.add(l[1])

    firstDic = dict()
    secondDic = dict()

    for word in firstSet:
        firstDic[word] = 0
    for word in secondSet:
        secondDic[word] = 0

    for l in inputList[1:]:
        firstDic[l[0]] += 1
        secondDic[l[1]] += 1

    ##################################
    fakeCount = 0
    didFindNow = True

    while didFindNow == True:
        didFindNow = False
        for l in inputList[1:]:
            if firstDic[l[0]] > 1 and secondDic[l[1]] > 1:
                firstDic[l[0]] = firstDic[l[0]] - 1
                secondDic[l[1]] = secondDic[l[1]] - 1
                fakeCount += 1
                didFindNow = True
                break
    print fakeCount
    return fakeCount
    

    
def fullSolve(inFileName, outFileName):
    (T,lst) = readFileIntoList(inFileName);
    lst2 = []

    hasNum = False
    num = 0
    for i in range(len(lst)):
        if hasNum == False:
            hasNum = True
            nxtLst = [lst[i][0]]
            num = int(lst[i][0])
        else:
            nxtLst.append(lst[i])
            num -= 1
            if num == 0:
                hasNum = False
                lst2.append(nxtLst)
    f = open(outFileName, 'w');
    for i in range(len(lst2)):
        sol = Technobabble(lst2[i])
        f.write("Case #" + str(i+1) + ": " + str(sol) + "\n")
    f.close()

fullSolve(inputFileName, outputFileName)
