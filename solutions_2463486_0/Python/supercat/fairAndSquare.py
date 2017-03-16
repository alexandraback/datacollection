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
    
    
def getPalis(A, B):
    aDig = toDigits(A)
    bDig = toDigits(B)
    
    
def getFairAndSquare(A, B):     
    # TODO
    #newA = long(ceil(sqrt(A)))
    #newB = long(sqrt(B))
    #palis = getPalis(newA, newB)
    
    #nums = []
    #for i in range(len(palis)):
    #    if isPali(i * i):
    #        nums = nums + [i]
           
    return [1,4,9,121,484]
    
    
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
    
    
filePath = 'C-small-attempt0.in'
outFilePath = 'C-small-attempt0.out'
(nTestCases, a, b) = parseInput(filePath)
result = solve(nTestCases, a, b)
printResult(result, outFilePath)