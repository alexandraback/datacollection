#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

def countRecyledNumber(n, B):
    count = 0
    mSet = set()
    nStr = str(n)
    for i in range(1, len(nStr)):
        m = int(nStr[i:] + nStr[:i])
        if n < m and m <= B and m not in mSet:
            count += 1
            mSet.add(m)
    return count

def solve(line):
    A = int(line[0])
    B = int(line[1])
    result = 0
    for n in range(A, B + 1):
        result += countRecyledNumber(n, B)
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
