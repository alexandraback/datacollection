def isRecycled(n, m):    
    for i in range(len(n)-1):
        if n[i+1::] + n[0:i+1:] == m:
            return True
    return False

inFile = open("in3.txt")
outFile = open("out3.txt", 'w')

numCases = int(inFile.readline())
for i in range(1, numCases+1):
    line = inFile.readline().split()
    a = int(line[0])
    b = int(line[1])
    
    count = 0
    for x in range(a, b):
        for y in range(x+1, b+1):
            if len(str(x)) == len(str(y)) and isRecycled(str(x), str(y)):
                count += 1
    
    outFile.write("Case #" + str(i) + ": " + str(count) + '\n')