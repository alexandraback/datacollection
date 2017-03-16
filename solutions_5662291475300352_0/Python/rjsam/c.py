import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        iCnt = int(sys.stdin.readline().strip())
        hList = []
        for j in range(iCnt):
            iList = tuple([int(x.strip()) for x in sys.stdin.readline().split()])
            hList.append(iList)

        if iCnt == 1:
            print("Case #{0}: 0".format(i+1))
            continue

        if hList[0][2] == hList[1][2]:
            print("Case #{0}: 0".format(i+1))
            continue

        hList.sort(key=operator.itemgetter(2))
        tSlow = hList[1][0]*hList[1][2]/360.0
        tFast = hList[0][0]*hList[0][2]/360.0
        relSpeed = 360.0/hList[0][2] - 360.0/hList[1][2]
        sDist = tFast*360.0/hList[1][2]
        sPos = hList[1][0] - sDist
        if sPos < 0.0:
            sPos += 360.0
        eTime = (360.0 - sPos)*relSpeed/360.0

        if eTime + tFast <= tSlow:
            print("Case #{0}: 1".format(i+1))
            continue

        print("Case #{0}: 0".format(i+1))
    return 0

main()
