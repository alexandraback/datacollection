import sys

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        sCnt, sVal = tuple([x.strip() for x in sys.stdin.readline().split()])
        sCnt = int(sCnt)
        sVal = [int(x) for x in list(sVal)]

        aCnt = sVal[0]
        fVal = 0
        for j in range(1, sCnt+1):
            if aCnt >= j:
                aCnt += sVal[j]
            else:
                nVal = j - aCnt
                fVal += nVal
                aCnt += (nVal + sVal[j])

        print("Case #{0}: {1}".format(i+1, fVal))

    return 0

main()
