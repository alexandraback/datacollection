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
        
        if 3 < xVal < 7 and (rVal < oSpread[xVal] or cVal < oSpread[xVal]):
            print("Case #{0}: RICHARD".format(i+1))
            continue

        if xVal > 6:                                #THIS COULD BE VERY POSSIBLY WRONG. BUT FOR X > 6 THERE CAN EXIST AN X-OMINO WITH A HOLE
            print("Case #{0}: RICHARD".format(i+1)) #SUCH AN OMINO, IF CHOSEN BY RICHARD, SHOULD MAKE IT IMPOSSIBLE FOR GABRIEL TO WIN
            continue

        print("Case #{0}: GABRIEL".format(i+1))
    return 0

main()
