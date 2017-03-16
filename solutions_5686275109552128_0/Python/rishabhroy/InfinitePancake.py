#-------------------------------------------------------------------------------
# Name: Infinite house of pancakes
# Purpose:
#
# Author:      rishabh
#
# Created:     12/04/2015
# Copyright:   (c) Rishabh 2015
# Licence:     <MIT licence>
#-------------------------------------------------------------------------------

#!/usr/bin/env python3.4
import sys
import math

if __name__ == '__main__':
    for testCase in range(int(sys.stdin.readline())):
        dinerCount = int(sys.stdin.readline())
        plates = sorted(map(int, sys.stdin.readline().split()), reverse=True)
        maxRound = plates[0]
        minTime = float('inf')
        for r in range(1, maxRound + 1):
            moveRound = 0
            for plate in plates:
                if plate <= r:
                    break
                moveRound += math.ceil(float(plate) /float( r)) - 1
            if moveRound + r < minTime:
                minTime = moveRound + r

        print('Case #%d: %d' % (testCase + 1, minTime))

