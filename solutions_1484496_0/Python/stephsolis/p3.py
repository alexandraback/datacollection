import itertools

def subsets(_set, length):        
    return list(itertools.combinations(_set, length))

def sum(_set):
    out = 0
    for x in _set:
        out += x
    return out

def printable(_set):
    out = ""
    for x in _set:
        out += str(x) + " "
    return out

inFile = open("in.txt")
outFile = open("out.txt", 'w')

numCases = int(inFile.readline())
for i in range(1, numCases+1):
    currLine = inFile.readline().strip()
    
    numbers = currLine.split()[1::]
    for x in range(len(numbers)):
        numbers[x] = int(numbers[x])
    
    sums = {}
    done = False
    
    for x in range(1, len(numbers) + 1):
        currnums = subsets(numbers, x)
        if done:
            break
        for currSet in currnums:
            currSum = sum(currSet)
            if done:
                break
            if currSum in sums:
                done = True
                set1 = currSet
                set2 = sums[currSum]
            else:
                sums[currSum] = currSet
            
    outFile.write("Case #" + str(i) + ":" + '\n')
    if not done:
        outFile.write("Impossible" + '\n')
    else:
        outFile.write(printable(set1) + '\n')
        outFile.write(printable(set2) + '\n')