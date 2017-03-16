import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        c, d, v = tuple([int(x.strip()) for x in sys.stdin.readline().split()])
        dList = [int(x.strip()) for x in sys.stdin.readline().split()]

        nVal = 0
        for j in range(1, v+1):
            if j not in dList:
                rList = [x for x in dList if x <= j]
                if not rList:
                    nVal += 1
                    dList.append(j)
                    dList.sort()
                else:
                    k = 0
                    tVal = j
                    iFlag = False
                    rList.sort(reverse=True)
                    while k < len(rList):
                        if tVal in rList:
                            iFlag = True
                            break
                        dVal = rList[k]
                        if tVal == dVal*2:
                            dList.append(tVal)
                            dList.sort()
                            nVal += 1
                            iFlag = True
                            break
                        if dVal < tVal:
                            tVal -= dVal
                        k += 1

                    if iFlag:
                        continue

                    dList.append(tVal)
                    dList.sort()
                    nVal += 1

        print("Case #{0}: {1}".format(i+1, nVal))

    return 0

main()
