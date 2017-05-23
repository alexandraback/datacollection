# Google Code Jam 2015 Qualifying B.

import sys

# How many splits does it take to convert num pancakes into stacks
# not taller than target?
def countSplits(num, target):
    if num <= 1:
        return 0
    # We do (9,3) by removing 3 twice (making 3 stacks of 3).
    return (num - 1) / target

def doCase(file):
    file.readline()             # Ignore number of plates
    plates = map(int, file.readline().split())
    bestCost = 1000
    for targetStack in range(1, 1001):
        cost = targetStack      # cost of eating stack after splitting
        for plate in plates:
            cost += countSplits(plate, targetStack) # cost of splitting
        bestCost = min(bestCost, cost)
        #print "Target {0}, cost {1}".format(targetStack, cost)
    return bestCost

def run():
    file = open(sys.argv[1])
    numCases = int(file.readline())
    for case in range(1, numCases+1):
        answer = doCase(file)
        print 'Case #{0}: {1}'.format(case, answer)
run()
