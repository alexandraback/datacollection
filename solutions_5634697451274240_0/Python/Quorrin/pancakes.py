f = open('input.in', 'r')
n = int(f.readline().strip())
out = open('output.txt', 'w')

pancakeDict = {}

def condenseStack(pancakes):
    newStack = []
    previous = ""
    for i in range(len(pancakes)):
        if pancakes[i] != previous:
            newStack.append(pancakes[i])
            previous = pancakes[i]
    return newStack

def flipSign(sign):
    if (sign == '-'):
        return '+'
    else:
        return '-'

def reverse(inArr, idx):
    dx = 0
    retArr = list(inArr)
    for i in range(idx):
        if (i >= idx-i):
            return retArr
        else:
            dx = retArr[idx-i-1]
            retArr[idx-i-1] = flipSign(retArr[i])
            retArr[i] = flipSign(dx)
    return retArr

def getClearedLevel(inputArr):
    for i in range(len(inputArr), 0, -1):
        if (inputArr[i-1] == '-'):
            return i
    return 0

def flipped(inArr):
    for i in range(len(inArr)):
        if (inArr[i] == '-'):
            return False
    return True

def dp(inputArr, depth, unsortedLevel):
    if (unsortedLevel == 0):
        return depth
    elif (depth > 20):
        return 20
    else:
        minDepth = 200
        for i in range(1,unsortedLevel+1):
            newPancakes = condenseStack(reverse(inputArr, i))
            pHash = ''.join(newPancakes)
            if (pHash in pancakeDict):
                return pancakeDict[pHash]
            else:
                currentDepth = dp(newPancakes, depth+1, getClearedLevel(newPancakes))
                pancakeDict[pHash] = currentDepth
                if (currentDepth < minDepth):
                    minDepth = currentDepth
        return minDepth
        

for i in range(n):
    inputStr = f.readline().strip()
    pancakes = condenseStack(list(inputStr))
    print (pancakes)
    count = -1
    if (len(inputStr) == 0):
        count = 0
    elif (len(inputStr) == 1):
        if (inputStr == "-"):
            count = 1
        else:
            count = 0
    else:
        pancakeDict = {}
        count = dp(pancakes, 0, getClearedLevel(pancakes))
    print (count)
    out.write("Case #" + str(i+1) + ": " + str(count)+ "\n")
     
  
out.close()
f.close()


