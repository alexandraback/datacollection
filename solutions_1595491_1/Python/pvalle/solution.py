
import string, os, time, sys


def GetNonSurpriseMax(n):
    if (n == 0): return 0
    
    div = n / 3
    mod = n % 3
    if mod == 0:
        return div
    else:
        return div+1
    
def GetSurpriseMax(n):
    if (n == 0): return 0

    div = n / 3
    mod = n % 3
    if mod == 2:
        return div+2
    else:
        return div+1
    
def HandleCase(f, caseIndex):
    caseline = f.readline().rstrip("\r\n")
    result = ""
    splitline = caseline.split(" ")

    numPeople = int(splitline[0])
    splitline = splitline[1:]
    maxNumSurprises = int(splitline[0])
    splitline = splitline[1:]
    targetVal = int(splitline[0])
    splitline = splitline[1:]

    result = 0
    for next in splitline:
        i = int(next)
        if GetNonSurpriseMax(i) >= targetVal:
            result += 1
        elif (maxNumSurprises > 0 and
              GetSurpriseMax(i) >= targetVal):
            maxNumSurprises -= 1
            result += 1

    print "Case #%(count)d: %(r)d" % {"count":caseIndex, "r":result}


inputFile = sys.argv[1]
f = open(inputFile, "r")
numCases = int(f.readline())
for i in range(0, numCases):
    HandleCase(f, i+1)

