def rankAndFile(rowsAndColumns):
    result = []
    counts = {}
    for rowOrColumn in rowsAndColumns:
        for n in rowOrColumn.split():
            actualN = int(n)
            if actualN in counts:
                counts[actualN] = counts[actualN] + 1
                #print counts
            else:
                counts[actualN] = 1
    #print counts
    for key in sorted(counts.keys()):
        #print key
        if counts[key] % 2 != 0:
            result.append(str(key))
    return " ".join(result)

##print rankAndFile([["1 2 3"],
##["2 3 5"],
##["3 5 6"],
##["2 3 4"],
##["1 2 3"]])

readFile = open("B-large.in")
writeFile = open("B-large.out", "a")

numberOfTestCases = -1
N = -1
caseNumber = 1
rowsAndColumns = []
for line in readFile.readlines():
    if(numberOfTestCases == -1):
        numberOfTestCases = int(line)
        continue
    if N == -1:
        N = int(line) * 2 - 1
        #print N
        continue
    else:
        rowsAndColumns.append(line)
        if N == 1:
            writeFile.write("Case #" + str(caseNumber) + ": " + rankAndFile(rowsAndColumns) + "\n")
            caseNumber = caseNumber + 1

            N = -1
            #print N
            rowsAndColumns = []
        else:
            N = N - 1
            #print N
    

readFile.close()
writeFile.close()
