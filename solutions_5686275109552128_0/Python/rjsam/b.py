import sys
import math

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        dCnt = int(sys.stdin.readline().strip())
        pList = [int(x.strip()) for x in sys.stdin.readline().split()]

        maxCakes = max(pList)
        maxTime = maxCakes
        for j in range(1, maxCakes):
            cutCnt = 0
            for k in range(dCnt):
                cutCnt += int(math.ceil(float(pList[k])/j)) - 1
            timeVal = cutCnt + j
            if timeVal < maxTime:
                maxTime = timeVal

        print("Case #{0}: {1}".format(i+1, maxTime))

    return 0

main()
