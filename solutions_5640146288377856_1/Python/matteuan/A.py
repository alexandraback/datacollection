__author__ = 'matteuan'

def solveNum(R, C, W):
    if (W == 1):
        return R*C
    numEachC = C // W
    result = (numEachC*R) + W
    if(C%W == 0):
        return result - 1
    else:
        return result

def solve(a):
    result = []
    for i in a:
        str = i.split(' ')
        R = int(str[0])
        C = int(str[1])
        W = int(str[2])
        result.append(solveNum(R, C, W))
    return result

inputFileName = input("nome file:\n")
fileInput = open(inputFileName, mode='r')
n = int(fileInput.readline())
array = []
for i in range(1,n+1):
    line = fileInput.readline()
    array.append(line)
fileInput.close()
solution = solve(array)
outputFileName = inputFileName + 'Out'
fileOutput = open(outputFileName, mode='w')
count = 1
for i in solution:
    fileOutput.write('Case #' + str(count) + ': ' + str(i) + '\n')
    count += 1
fileOutput.close()

