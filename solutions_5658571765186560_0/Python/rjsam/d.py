import sys
import math

def main():
    cCnt = int(sys.stdin.readline().strip())
    oSpread = dict([(4, 3), (5, 4), (6, 4)])        #PARAMETER THAT DECIDES IF A SUFFICIENTLY BRANCHED OMINO CAN CAUSE TROUBLE IN A GRID
    for i in range(cCnt):
        xVal, rVal, cVal = tuple([int(x.strip()) for x in sys.stdin.readline().split()])

        if (rVal*cVal)%xVal != 0:
            print("Case #{0}: RICHARD".format(i+1))
            continue
        else:
            if xVal == 1 or xVal == 2:
                print("Case #{0}: GABRIEL".format(i+1))
                continue

        if rVal == 1 or cVal == 1 or (rVal < xVal and cVal < xVal):
            print("Case #{0}: RICHARD".format(i+1))
            continue
        
        if xVal > 3 and (rVal < oSpread[xVal] or cVal < oSpread[xVal]):
            print("Case #{0}: RICHARD".format(i+1))
            continue

        print("Case #{0}: GABRIEL".format(i+1))
    return 0

main()
