INPUT_FILE = r'D:\Downloads\FromChrome\B-small-attempt1.in'
#INPUT_FILE = r'D:\Downloads\FromChrome\sample.in'
OUTPUT_FILE = INPUT_FILE.replace('.in', '.out')

inputFile = file(INPUT_FILE, 'rb')
numQuestions = int(inputFile.readline())
outputFile = file(OUTPUT_FILE, 'wb')

def iteration(B, M, y, slids):
    if 0 == M:
        return 'POSSIBLE'
    if y >= B:
        return 'IMPOSSIBLE'
    counter = y + 1
    while counter != B:
        slids[y][counter] = 1
        slids[counter][B - 1] = 1
        counter += 1
        M -= 1
        if 0 == M:
            return 'POSSIBLE'
    return iteration(B - 1, M, y + 1, slids)

def solveQuestion(B, M, minX=1):
    slids = []
    for i in xrange(B):
        slids.append([0] * B)
    if 0 == M:
        result = 'POSSIBLE'
    else:
        x = 1
        slids[0][B-1] = 1
        M -= 1
        while (M > 0) and (x < (B - 1)):
            slids[x][B-1] = 1
            slids[0][x] = 1
            M -= 1
            x += 1
        if 0 == M:
            result = 'POSSIBLE'
        else:
            result = iteration(B-1, M, 0, slids)
    if 'POSSIBLE' == result:
        result += '\n'
        for l in slids:
            result += ''.join([str(x) for x in l])
            result += '\n'
    return result.strip()

for q in xrange(numQuestions):
    outputFile.write("Case #%d: " % (q+1))
    # Don't forget to read length of a list
    B, M = [int(x) for x in inputFile.readline().strip().split()]
    result = solveQuestion(B, M)
    outputFile.write(result)
    outputFile.write("\n")

outputFile.close()
inputFile.close()
# print file(OUTPUT_FILE, 'rb').read()
