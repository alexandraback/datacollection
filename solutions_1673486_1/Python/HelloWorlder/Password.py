#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

def solve(A, B, line):
    pList = map(float, line.split())
    pCur = 1
    # choice1 is contained in choice2 when i == A
    choice2 = A + B + 1
    for i, p in enumerate(pList):
        pCur *= p
        i += 1
        choice = pCur * ((A - i) + (B - i) + 1) + (1 - pCur) * (((A - i) + (B - i) + 1) + (B + 1))
        if choice < choice2:
            choice2 = choice

    choice3 = 1 + B + 1
    result = min(choice2, choice3)
    return "%.6f" % result

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
        A, B = map(int, inFile.readline().strip().split())
        line = inFile.readline().strip()
        result = solve(A, B, line)
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
