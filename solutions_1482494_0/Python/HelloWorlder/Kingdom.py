#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

def solve(N, levels):
    result = 0
    numStar = 0
    while numStar != N * 2:
        print levels
        toFinishLevel = None
        starLevel = 0
        for level in levels:
            star = level[2]
            # Got 2 stars for this level
            if star == 2:
                continue
            # Can't play this level for more stars
            if level[star] > numStar:
                continue
            # Required number of stars to get 2 stars in this level
            if numStar >= level[1]:
                numStar += 2 if star == 0 else 1
                level[2] = 2
                result += 1
                starLevel = 2
                break
            elif numStar >= level[0]:
                if not toFinishLevel or level[1] > toFinishLevel[1]:
                    toFinishLevel = level
                starLevel = 1
        if starLevel == 2:
            pass
        elif starLevel == 1:
            numStar += 1
            toFinishLevel[2] = 1
            result += 1
        elif numStar != N * 2:
            return "Too Bad"
    return result

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit();

    inFile = open(sys.argv[1])
    outFile = open(sys.argv[2], "w")

    startTime = datetime.datetime.now()
    print "Start Time = %s" % startTime
    print SEPARATE_LINE

    T = int(inFile.readline())
    for i in range(T):
        N = int(inFile.readline().strip())
        levels = list()
        for j in range(N):
            a, b = map(int, inFile.readline().strip().split())
            levels.append([a, b, 0])
        result = solve(N, levels)
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
