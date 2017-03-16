import sys
import math
import scipy
import operator
import fractions

def main():
    cCnt = int(sys.stdin.readline().strip())
    for i in range(cCnt):
        r, c, w = tuple([int(x.strip()) for x in sys.stdin.readline().split()])
        nT = c/w
        if c%w != 0:
            nT += 1

        nT += w-1

        print("Case #{0}: {1}".format(i+1, nT*r))

    return 0

main()
