import re

def parseInput(filePath):
    f = open(filePath, 'r')
    numRE = re.compile('\d+')
    
    # Parse number of test cases
    line = f.readline()
    nTestCases = int(line)
    
    # Parse each test case
    a = [0 for i in range(nTestCases)]
    b = [0 for i in range(nTestCases)]
    for i in range(nTestCases):    
        # Parse size of test case
        line = f.readline()
        numStr = numRE.findall(line)
        a[i] = long(numStr[0])
        b[i] = long(numStr[1])
    
    # Return test case data
    return (nTestCases, a, b)
    
    
def toDigits(x):
    digits = [x % 10]
    x = x / 10
    while x > 0:
        digits = [x % 10] + digits
        x = x / 10
    return digits
    
    
def fromDigits(dig):
    x = 0
    for i in range(len(dig)):
        x *= 10
        x += dig[i]
    return x
    

def isPali(x):
    dig = toDigits(x)
    for i in range(len(dig)/2):
        if dig[i] != dig[len(dig)-1-i]:
            return False
    return True
    
    
def getPalis(A, B):
    aDig = toDigits(A)
    bDig = toDigits(B)
    
    
def getFairAndSquare(A, B):    
    nInit = 100000
    nums = [x for x in range(nInit)]
    digits = [toDigits(nums[i]) for i in range(nInit)]
    
    palis = [0 for i in range(nInit)]
    palis2 = [0 for i in range(nInit)]
    for i in range(nInit):
        palis[i] = fromDigits(digits[i] + digits[i][::-1])
        palis2[i] = fromDigits(digits[i] + digits[i][-2::-1])
            
    
    palis = palis + palis2
    print palis
    
    fs = []
    for i in range(len(palis)):
        sq = palis[i] * palis[i]
        if isPali(sq):
            fs = fs + [sq]
    
    return fs
    
    
def solve(nTestCases, a, b):
    minA = min(a)
    maxB = max(b)
    
    nums = getFairAndSquare(minA, maxB)
    
    result = [0 for i in range(nTestCases)]
    
    for i in range(nTestCases):
        for j in range(len(nums)):
            if a[i] <= nums[j] and nums[j] <= b[i]:
                result[i] += 1
        
    return result
    
    
    
def printResult(result, outFilePath):
    f = open(outFilePath, 'w')
    for i in range(len(result)):
        s = 'Case #%d: %d' % (i+1, result[i])
        print >> f, s
    f.close()
    
    
filePath = 'C-large-1.in'
outFilePath = 'C-large-1.out'
(nTestCases, a, b) = parseInput(filePath)
result = solve(nTestCases, a, b)
printResult(result, outFilePath)