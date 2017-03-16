
import string, os, time, sys

#abcdefghijklmnopqrstuvwxyz


def ExpectedKeystrokes(numtyped, strlen, probs, numBS):
    noFailKeystrokes = numBS * 2 + strlen - numtyped + 1
    failKeystrokes = noFailKeystrokes + strlen + 1
    probNoFail = 1
    for i in range(0, numtyped-numBS):
        probNoFail *= probs[i]

    return probNoFail * noFailKeystrokes + (1.0 - probNoFail) * failKeystrokes


def HandleCase(f, caseIndex):
    caseline = f.readline().rstrip("\r\n")
    splitline = caseline.split(" ")

    A = int(splitline[0])
    B = int(splitline[1])

    caseline = f.readline().rstrip("\r\n")
    splitline = caseline.split(" ")

    probs = []
    for num in splitline:
        probs.append(float(num))

    result = B + 2
    for i in range(0, A):
        num = ExpectedKeystrokes(A, B, probs, i)
        result = min(result, num)

    print "Case #%(count)d: %(r)f" % {"count":caseIndex, "r":result}


inputFile = sys.argv[1]
f = open(inputFile, "r")
numCases = int(f.readline())
for i in range(0, numCases):
    HandleCase(f, i+1)

