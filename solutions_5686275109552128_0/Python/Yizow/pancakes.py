import Queue
import sys

def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                numDiners = int(inputFile.readline())
                pancakes = inputFile.readline().split()
                pancakes = [int(p) for p in pancakes]
                stack = Queue.PriorityQueue()
                [stack.put(-p) for p in pancakes]

                print "Test %s" % (testNum+1,)
                minutes = calcTotalTime(pancakes) 
                print
                outputFile.write("Case #%d: %d" % (testNum+1, minutes))

# Splits a pile evenly into sub-piles that are all less than limit. 
def splitPile(pile, limit):
    # Integer division exploit to round up
    numPiles = -(-pile/limit)
    piles = [pile/numPiles] * numPiles
    for i in range(pile % numPiles):
        piles[i] += 1
    return piles


def limitStack(stack, limit):
    newStack = []
    specialMinutes = 0
    for pile in stack:
        if pile <= limit:
            newStack.append(pile)
        else:
            newPiles = splitPile(pile, limit)
            newStack += newPiles
            specialMinutes += len(newPiles) - 1
    return newStack, specialMinutes

def calcTotalTime(stack):
    timeCosts = []
    maxPancake = max(stack)
    for limit in reversed(range(1, maxPancake+1)):
        newStack, specialMinutes = limitStack(stack, limit)
        timeCosts.append(max(newStack) + specialMinutes)
    if len(timeCosts) == 0:
        return 1
    return min(timeCosts)


main()