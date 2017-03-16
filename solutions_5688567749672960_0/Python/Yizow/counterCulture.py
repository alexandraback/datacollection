import sys

import math


def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                print testNum

                N = int(inputFile.readline())

                outputFile.write("Case #%d: %d" % (testNum+1, calcSteps(N)))


def calcSteps(N):
    count = 0
    if N % 10 == 0 and N>10:
        N = N - 1
        count += 1
    num = 1
    # print "New N"
    while int(math.log10(N)) > int(math.log10(num)):
        count += increaseDigit(num)
        num *= 10

    count += countUp(N)
    return count


def countUp(N):
    digits = int(math.log10(N)) +1
    if digits == 1:
        return N
    halfway = (digits+1)/2
    rest = digits - halfway
    lower = int(str(N)[rest:])-1
    # print "count"
    # print N
    # print str(N)    [:rest]
    upper = int((str(N)[:rest])[::-1])
    if upper == 1:
        upper = 0
    # print lower, upper
    # if digits == 2 and N/pow(10,digits-1) == 1:
    #     lower -= 1
    return lower+upper+1
    
def increaseDigit(N):
    digits = int(math.log10(N)) +1
    halfway = (digits+1)/2
    rest = digits - halfway
    return pow(10,halfway) + pow(10,rest) -1

main()