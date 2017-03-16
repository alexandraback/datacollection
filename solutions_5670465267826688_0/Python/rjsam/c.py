import sys
import math

qList = ['1', 'i', 'j', 'k']

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        sLen, rVal = tuple([int(x.strip()) for x in sys.stdin.readline().split()])
        sVal = sys.stdin.readline().strip()

        if sLen == 1 or sLen*rVal < 3:
            print("Case #{0}: NO".format(i+1))
            continue

        passCheck = checkPass(sVal, sLen, rVal)
        print("Case #{0}: {1}".format(i+1, passCheck))

    return 0

def checkPass(sVal, sLen, rVal):
    mulVal = 1
    for j in range(rVal):
        for k in range(sLen):
            mulVal = quatMul(mulVal, qList.index(sVal[k]) + 1)

    if mulVal != -1:
        return "NO"

    sProd = 1
    for j in range(sLen):
        sProd = quatMul(sProd, qList.index(sVal[j]) + 1)

    iPts = []
    mulVal = 1
    for j in range(rVal):
        for k in range(sLen):
            mulVal = quatMul(mulVal, qList.index(sVal[k]) + 1)
            if mulVal == 2:
                iPts.append((j, k))

    kPts = []
    mulVal = 1
    for j in reversed(range(rVal)):
        for k in reversed(range(sLen)):
            mulVal = quatMul(qList.index(sVal[k]) + 1, mulVal)
            if mulVal == 4:
                kPts.append((j, k))

    iPts = [(x[0], x[1], x[0]*sLen + x[1]) for x in iPts]
    kPts = [(x[0], x[1], x[0]*sLen + x[1]) for x in kPts]
    for eachPt in iPts:
        posKs = [x for x in kPts if x[2] > eachPt[2]]
        if not posKs:
            break

        mulVal = 1
        firstK = posKs[0]
        if firstK[0] == eachPt[0]:
            for j in range(eachPt[1]+1, firstK[1]):
                mulVal = quatMul(mulVal, qList.index(sVal[j]) + 1)
        else:
            for j in range(eachPt[1]+1, sLen):
                mulVal = quatMul(mulVal, qList.index(sVal[j]) + 1)
            for j in range(eachPt[0] + 1, firstK[0]):
                mulVal = quatMul(mulVal, sProd)
            for j in range(firstK[1]):
                mulVal = quatMul(mulVal, qList.index(sVal[j]) + 1)

        if mulVal == 3:
            return "YES"

        for j in range(1, len(posKs)):
            if posKs[j][0] == posKs[j-1][0]:
                for k in range(posKs[j-1][1]+1, posKs[j][1]):
                    mulVal = quatMul(mulVal, qList.index(sVal[k]) + 1)
            else:
                for k in range(posKs[j-1][1]+1, sLen):
                    mulVal = quatMul(mulVal, qList.index(sVal[k]) + 1)
                for k in range(posKs[j-1][0] + 1, posKs[j][0]):
                    mulVal = quatMul(mulVal, sProd)
                for k in range(posKs[j][1]):
                    mulVal = quatMul(mulVal, qList.index(sVal[k]) + 1)
            if mulVal == 3:
                return "YES"

    return "NO"


def quatMul(a, b):
    matTable = [[1, 2, 3, 4],
                [2,-1, 4,-3],
                [3,-4,-1, 2],
                [4, 3,-2,-1]]
    mulVal = matTable[abs(a)-1][abs(b)-1]
    mulVal *= int(math.copysign(1, a))*int(math.copysign(1, b))
    return mulVal

main()
