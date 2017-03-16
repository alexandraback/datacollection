#!/usr/bin/python

import sys

PROBLEMSIZE=int(sys.stdin.readline())

for t in range(PROBLEMSIZE):
    numberOfBlocks = int(sys.stdin.readline())
    naomisBlocks = [float(x) for x in sys.stdin.readline().split(" ")]
    kensBlocks = [float(x) for x in sys.stdin.readline().split(" ")]
    naomisBlocks.sort()
    kensBlocks.sort()
    naomiWins = 0
    kenWins = 0
    for x in range(numberOfBlocks):
# Deceitful War
        if naomisBlocks[x] < kensBlocks[x-kenWins]:
            kenWins += 1
# regular War
        if kensBlocks[x] < naomisBlocks[x-naomiWins]:
            naomiWins += 1
    print("Case #%s: %s %s " % (str(t+1),(numberOfBlocks-kenWins),naomiWins))
