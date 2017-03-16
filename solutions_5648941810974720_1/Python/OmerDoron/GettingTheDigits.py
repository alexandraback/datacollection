inputFileName = "C:\\Users\\t8081591\\Desktop\\A-large.in"
outputFileName = "C:\\Users\\t8081591\\Desktop\\A-large.out"

def readFileIntoList(fileName):
    with open(fileName) as f:
        content = f.readlines()
        contentFixed = [c.split() for c in content[1:]]
        T = int(content[0])
    return (T,contentFixed)

def GettingTheDigits(inputList):
    s = inputList[0]
    ascii = [0 for i in range(26)]
    for c in s:
        ascii[ord(c) - 65] += 1

    solution = [0 for i in range(10)]
    solution[0] += ascii[ord('Z')-65]
    solution[2] += ascii[ord('W')-65]
    solution[4] += ascii[ord('U')-65]
    solution[6] += ascii[ord('X')-65]
    solution[8] += ascii[ord('G')-65]

    deleteAllLettersTimes(ascii[ord('Z')-65], ascii, ['Z','E','R','O'])
    deleteAllLettersTimes(ascii[ord('W')-65], ascii, ['T','W','O'])
    deleteAllLettersTimes(ascii[ord('U')-65], ascii, ['F','O','U','R'])
    deleteAllLettersTimes(ascii[ord('X')-65], ascii, ['S','I','X'])
    deleteAllLettersTimes(ascii[ord('G')-65], ascii, ['E','I','G','H','T'])

    solution[1] += ascii[ord('O')-65]
    solution[3] += ascii[ord('H')-65]
    solution[5] += ascii[ord('F')-65]
    solution[7] += ascii[ord('S')-65]
    solution[9] += (ascii[ord('N')-65] - solution[1] - solution[7])/2

    sol = ''
    for i in range(10):
        sol += str(i)*solution[i]
    print sol
    return sol
    

    

def deleteAllLettersTimes(times, ascii, letters):
    for l in letters:
        ascii[ord(l) - 65] -= times

def fullSolve(inFileName, outFileName):
    (T,lst) = readFileIntoList(inFileName);
    f = open(outFileName, 'w');
    for i in range(T):
        sol = GettingTheDigits(lst[i])
        f.write("Case #" + str(i+1) + ": " + str(sol) + "\n")
    f.close()

fullSolve(inputFileName, outputFileName)
