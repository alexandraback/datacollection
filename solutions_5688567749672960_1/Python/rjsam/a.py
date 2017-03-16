import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        iNum = int(sys.stdin.readline().strip())
        nCnt = 0
        while iNum > 10:
            if iNum%10 == 0:
                iNum -= 1
                nCnt += 1
                continue

            iStr = str(iNum)
            hNum = int(iStr[-len(iStr)/2:]) - 1
            nCnt += hNum
            iNum -= hNum

            if iNum == int(str(iNum)[::-1]):
                iNum -= 1
                nCnt += 1
            else:
                iNum = int(str(iNum)[::-1])
                nCnt += 1

        print("Case #{0}: {1}".format(i+1, nCnt+iNum))

    return 0

main()
