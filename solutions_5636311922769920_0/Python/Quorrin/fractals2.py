f = open('input.in', 'r')
n = int(f.readline().strip())
out = open('output2.txt', 'w')

def findTile(overallIdx, intrablockIdx, curDepth, K, C):
    if (curDepth > C):
        return overallIdx
    elif (intrablockIdx < K):
        intrablockIdx += 1
    newIdx = K * (overallIdx - 1) + intrablockIdx
    if (curDepth >= C):
        return newIdx
    else:
        return findTile(newIdx, intrablockIdx, curDepth+1, K, C)

for i in range(n):
    inputStr = f.readline().strip().split(' ')
    K = int(inputStr[0])
    C = int(inputStr[1])
    S = int(inputStr[2])
    minTries = -(-K//C)
    if (S < minTries):
        print ("IMPOSSIBLE")
        out.write("Case #" + str(i+1) + ": IMPOSSIBLE\n")
    else:
        results = []
        for j in range(minTries):
            startIdx = 1 + j * C
            results.append(str(findTile(startIdx, startIdx, 2, K, C)))
        print (results)
        out.write("Case #" + str(i+1) + ": " + ' '.join(results) + "\n")


out.close()
f.close()


