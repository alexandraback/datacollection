fileHandle = open('in.txt', 'r')
outputHandle = open('out.txt', 'w')

caseNumber = int(fileHandle.readline())

for i in range(caseNumber):
    [a, b, k] = [int(j) for j in fileHandle.readline().split(" ")]
    result = 0
    for m in range(a):
        for n in range(b):
            if m & n < k:
                result += 1
    outputHandle.write("Case #"+str(i+1)+": "+str(result)+"\n")

fileHandle.close()
outputHandle.close()