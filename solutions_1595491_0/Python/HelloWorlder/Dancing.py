#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

def solve(line):
    N = int(line[0])
    S = int(line[1])
    p = int(line[2])

    if p == 0:
        return N

    P1 = max(3 * p - 2, 0)
    P2 = max(3 * p - 4, 0)
    result = 0
    supprising = 0
    for i in line[3:]:
        t = int(i)
        if t >= P1:
            result += 1
        elif t >= P2 and t != 0:
            supprising += 1
    result += min(S, supprising)

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
        line = inFile.readline()
        result = solve(line.strip().split())
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
