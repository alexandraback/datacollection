def getLine(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        yield line
    inputFile.close()

inputFilename = 'B-small-attempt0.in'
outputFilename = 'B-small-attempt0.txt'

tokenIterator = getLine(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING

caseNum = getint()
for case in range(caseNum):

    dim = get().split()
    m = int(dim[0])
    n = int(dim[1])
    
    x = []
    for i in range(m):
        x.append([int(p) for p in get().split()])
        
    row = [0]*m
    col = [0]*n
        
    for i in range(m):
        for j in range(n):
            if row[i] < x[i][j]:
                row[i] = x[i][j]
            if col[j] < x[i][j]:
                col[j] = x[i][j]
    
    ans = 'YES'
    for i in range(m):
        for j in range(n):
            if row[i] > x[i][j] and col[j] > x[i][j]:
                ans = 'NO'
    
    output = "Case #"+str(case+1)+": "+str(ans)
    outputFile.write(output+"\n")

# BEGIN POST-PROCESSING
outputFile.close()

