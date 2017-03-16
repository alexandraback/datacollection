inputFileName = "C:\\Users\\t8081591\\Desktop\\B-small-attempt2.in"
outputFileName = "C:\\Users\\t8081591\\Desktop\\B-small-attempt2.out"

def readFileIntoList(fileName):
    with open(fileName) as f:
        content = f.readlines()
        contentFixed = [c.split() for c in content[1:]]
        T = int(content[0])
    return (T,contentFixed)

def CloseMatch(inputList):
    (c,j) = (inputList[0], inputList[1])
    sol = solveRec(c,j,0)
    return sol[0] + " " + sol[1]
    

def solveRec(c,j,whoWins):
    if c == '':
        return ('','')
    if whoWins == 1:
        c = c.replace("?", "0")
        j = j.replace("?", "9")
        return (c,j)
    elif whoWins == -1:
        c = c.replace("?", "9")
        j = j.replace("?", "0")
        return (c,j)
    else:
        if c[0] != '?' and j[0] != '?':
            if c[0] == j[0]:
                sol = solveRec(c[1:],j[1:],0)
            if c[0] > j[0]:
                sol = solveRec(c[1:],j[1:],1)
            if c[0] < j[0]:
                sol = solveRec(c[1:],j[1:],-1)
            return (c[0] + sol[0], j[0] + sol[1])
        if c[0] != '?' and j[0] == '?':
            sol0 = solveRec(c[1:],j[1:],0)
            (c0,j0) = (c[0] + sol0[0], c[0] + sol0[1])
            sol1 = solveRec(c[1:],j[1:],1)
            (c1,j1) = (c[0] + sol1[0], str(int(c[0])-1) + sol1[1])
            sol2 = solveRec(c[1:],j[1:],-1)
            (c2,j2) = (c[0] + sol2[0], str(int(c[0])+1) + sol2[1])

            if c[0] == '0':
                (c1,j1) = (9999999999999999999,0)
            elif c[0] == '9':
                (c2,j2) = (9999999999999999999,0)

            m = min(abs(int(c0)-int(j0)),abs(int(c1)-int(j1)),abs(int(c2)-int(j2)))
            if m == abs(int(c1)-int(j1)):
                return (c1,j1)
            elif m == abs(int(c0)-int(j0)):
                return (c0,j0)
            else:
                return (c2,j2)
        if c[0] == '?' and j[0] != '?':
            sol0 = solveRec(c[1:],j[1:],0)
            (c0,j0) = (j[0] + sol0[0], j[0] + sol0[1])
            sol1 = solveRec(c[1:],j[1:],1)
            (c1,j1) = (str(int(j[0])+1) + sol1[0], j[0] + sol1[1])
            sol2 = solveRec(c[1:],j[1:],-1)
            (c2,j2) = (str(int(j[0])-1) + sol2[0], j[0] + sol2[1])

            if j[0] == '0':
                (c2,j2) = (9999999999999999999,0)
            elif j[0] == '9':
                (c1,j1) = (9999999999999999999,0)

            m = min(abs(int(c0)-int(j0)),abs(int(c1)-int(j1)),abs(int(c2)-int(j2)))
            if m == abs(int(c2)-int(j2)):
                return (c2,j2)
            elif m == abs(int(c0)-int(j0)):
                return (c0,j0)
            else:
                return (c1,j1)
            
        if c[0] == '?' and j[0] == '?':
            sol0 = solveRec(c[1:],j[1:],0)
            (c0,j0) = ('0' + sol0[0], '0' + sol0[1])
            sol1 = solveRec(c[1:],j[1:],1)
            (c1,j1) = ('1' + sol1[0], '0' + sol1[1])
            sol2 = solveRec(c[1:],j[1:],-1)
            (c2,j2) = ('0' + sol2[0], '1' + sol2[1])

            m = min(abs(int(c0)-int(j0)),abs(int(c1)-int(j1)),abs(int(c2)-int(j2)))
            if m == abs(int(c0)-int(j0)):
                return (c0,j0)
            elif m == abs(int(c2)-int(j2)):
                return (c2,j2)
            else:
                return (c1,j1)
    
def fullSolve(inFileName, outFileName):
    (T,lst) = readFileIntoList(inFileName);
    f = open(outFileName, 'w');
    for i in range(T):
        sol = CloseMatch(lst[i])
        f.write("Case #" + str(i+1) + ": " + str(sol) + "\n")
    f.close()

fullSolve(inputFileName, outputFileName)
