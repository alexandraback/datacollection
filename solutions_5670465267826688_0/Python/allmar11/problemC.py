import sys

class SimpleQuaternion:
    _MULT_TABLE = [
        [1, 2, 3, 4],
        [2, -1, 4, -3],
        [3, -4, -1, 2],
        [4, 3, -2, -1]
        ]
    
    _UNIT_NAMES = ['1', 'i', 'j', 'k']
    
    def __init__(self, sign, unitIndex):
        self._value = sign * unitIndex
    
    @staticmethod
    def makeOne():
        return SimpleQuaternion(1, 1)
    
    @staticmethod
    def makeI():
        return SimpleQuaternion(1, 2)
    
    @staticmethod
    def makeJ():
        return SimpleQuaternion(1, 3)
    
    @staticmethod
    def makeK():
        return SimpleQuaternion(1, 4)
    
    def getSign(self):
        return -1 if self._value < 0 else 1
    
    def isOneDir(self):
        return self._getUnitIndex() == 1
    
    def isIDir(self):
        return self._getUnitIndex() == 2
    
    def isJDir(self):
        return self._getUnitIndex() == 3
    
    def isKDir(self):
        return self._getUnitIndex() == 4
    
    def isOne(self):
        return self.isOneDir() and (self.getSign() == 1)
    
    def isI(self):
        return self.isIDir() and (self.getSign() == 1)
    
    def isJ(self):
        return self.isJDir() and (self.getSign() == 1)
    
    def isK(self):
        return self.isKDir() and (self.getSign() == 1)
    
    def multiply(self, other):
        result = SimpleQuaternion._MULT_TABLE[self._getUnitIndex()-1] \
            [other._getUnitIndex()-1]
        result *= self.getSign() * other.getSign()
        return SimpleQuaternion(-1 if result < 0 else 1, abs(result))
    
    def multiplyInPlace(self, other):
        result = SimpleQuaternion._MULT_TABLE[self._getUnitIndex()-1] \
            [other._getUnitIndex()-1]
        result *= self.getSign() * other.getSign()
        self._value = result
    
    def leftMultiplyInPlace(self, other):
        result = SimpleQuaternion._MULT_TABLE[other._getUnitIndex()-1] \
            [self._getUnitIndex()-1]
        result *= self.getSign() * other.getSign()
        self._value = result
    
    def pow(self, exponent):
        # exponent must be a nonnegative integer.
        if self.isOne():
            return SimpleQuaternion.makeOne()
        
        elif self.isOneDir():
            return SimpleQuaternion(1 if exponent % 2 == 0 else -1, 1)
        
        elif exponent % 4 == 0:
            return SimpleQuaternion.makeOne()
        elif exponent % 4 == 3:
            return SimpleQuaternion(-self.getSign(), self._getUnitIndex())
        elif exponent % 4 == 2:
            return SimpleQuaternion(-1, 1)
        else:
            return SimpleQuaternion(self.getSign(), self._getUnitIndex())
    
    def _getUnitIndex(self):
        return abs(self._value)
    
    def __repr__(self):
        signStr = '-' if self.getSign() == -1 else ''
        unitStr = SimpleQuaternion._UNIT_NAMES[self._getUnitIndex()-1]
        return signStr + unitStr

def solve(quaternionList, numRepeats, letterCounts):
    # Make sure the string isn't all one letter.
    for count in letterCounts:
        if count == len(quaternionList):
            return False
    
    # First, compute the actual product of the quaternions to make sure it
    # it equals ijk = -1. If not, the quaternion sequence clearly is not
    # equivalent to ijk.
    firstI = -1
    firstISign = 0
    listProduct = SimpleQuaternion.makeOne()
    for idx, quaternion in enumerate(quaternionList):
        listProduct.multiplyInPlace(quaternion)
        if listProduct.isIDir() and firstI == -1:
            firstI = idx
            firstISign = listProduct.getSign()
    wholeProduct = listProduct.pow(numRepeats)
    if wholeProduct.isOne() or not wholeProduct.isOneDir():
        return False
    
    # Find the first index where the prefix product becomes equivalent to i or
    # -i, if there is one.
    if firstI == -1:
        for idx, quaternion in enumerate(quaternionList):
            listProduct.multiplyInPlace(quaternion)
            if listProduct.isIDir():
                firstI = len(quaternionList) + idx
                firstISign = listProduct.getSign()
                break
    
    # Return false if there is no prefix equivalent to i.
    if firstI == -1:
        return False
    
    # If a prefix equivalent to -i was found, keep searching until one
    # equivalent to i is found. (There will always be one, if quaternionList is
    # repeated enough times. At this point, we temporarily assume quaternionList
    # is repeated an infinite number of times.)
    firstPosI = -1 if firstISign == -1 else firstI
    nextIdx = (firstI + 1) % len(quaternionList)
    numIters = 0
    while firstPosI == -1:
        numIters += 1
        listProduct.multiplyInPlace(quaternionList[nextIdx])
        if listProduct.isI():
            firstPosI = firstI + numIters
        nextIdx = (nextIdx + 1) % len(quaternionList)
    
    # Find the first index where the prefix product becomes equivalent to k or
    # -k, if there is one.
    lastK = -1
    lastKSign = 0
    listProduct = SimpleQuaternion.makeOne()
    for idx, quaternion in enumerate(reversed(quaternionList)):
        listProduct.leftMultiplyInPlace(quaternion)
        if listProduct.isKDir():
            lastK = idx
            lastKSign = listProduct.getSign()
            break
    if lastK == -1:
        for idx, quaternion in enumerate(reversed(quaternionList)):
            listProduct.leftMultiplyInPlace(quaternion)
            if listProduct.isKDir():
                lastK = len(quaternionList) + idx
                lastKSign = listProduct.getSign()
                break
    
    # Return false if there is no suffix equivalent to k.
    if lastK == -1:
        return False
    
    # If a prefix equivalent to -k was found, keep searching until one
    # equivalent to k is found.
    lastPosK = -1 if lastKSign == -1 else lastK
    nextIdx = (len(quaternionList) - lastK - 2) % len(quaternionList)
    numIters = 0
    while lastPosK == -1:
        numIters += 1
        listProduct.leftMultiplyInPlace(quaternionList[nextIdx])
        if listProduct.isK():
            lastPosK = lastK + numIters
        nextIdx = (nextIdx - 1) % len(quaternionList)
    
    # If the "i" prefix and "k" suffix are small enough to leave space for a "j"
    # in the middle, the middle part must simplify to "j" since the whole string
    # simplifies to ijk = -1.
    prefixSize = firstPosI + 1
    suffixSize = lastPosK + 1
    return prefixSize + suffixSize < len(quaternionList) * numRepeats

if __name__ == '__main__':
#     inFile = sys.stdin
    # Read input from a file to work around the lack of support for using a file
    # as STDIN in Eclipse.
    inFile = open('input/C-small-attempt2.in')
    
    numCases = int(inFile.readline().rstrip())
    for case in range(1, numCases+1):
        inTokens = inFile.readline().split()
        listLen = int(inTokens[0])
        numRepeats = int(inTokens[1])
        quaternionList = [None] * listLen
        letterCounts = [0] * 3
        for idx, letter in enumerate(inFile.readline().rstrip()):
            letterIdx = ord(letter) - ord('i')
            letterCounts[letterIdx] += 1
            quaternionList[idx] = SimpleQuaternion(1, letterIdx + 2)
        
        result = solve(quaternionList, numRepeats, letterCounts)
        
        # Print result.
        resultStr = 'YES' if result else 'NO'
        print('Case #%s: %s' % (case, resultStr))
    
    inFile.close()