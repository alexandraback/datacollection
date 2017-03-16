#!/usr/bin/env python
#
# Problem: Deceitful War
# Language: Python
# Author: jjwon
# Usage: python thisfile.py < input.in > output.out

import fileinput
import random

def process(testCase):
    numBlocks = testCase[0]
    naomiBlocks = testCase[1]
    kenBlocks = testCase[2]

    y = deceitfulWar(numBlocks, sorted(naomiBlocks), sorted(kenBlocks))
    z = war(numBlocks, sorted(naomiBlocks), sorted(kenBlocks))
    return (y, z)

def war(numBlocks, naomiBlocks, kenBlocks):
    naomiPoints = 0
    for i in range(numBlocks):
        naomi = random.choice(naomiBlocks)
        if kenBlocks[-1] < naomi: # if the largest kenBlock is smaller, send the lowest-weight kenBlock to fight
            kenBlocks.pop(0)
            naomiPoints += 1
        else:
            for j in range(numBlocks):
                if kenBlocks[j] > naomi:
                    kenBlocks.pop(j)
                    break
        naomiBlocks.remove(naomi)
    return naomiPoints

def deceitfulWar(numBlocks, naomiBlocks, kenBlocks):
    naomiPoints = 0
    for i in range(numBlocks):
        if kenBlocks[0] < naomiBlocks[-1]: # if we can bait ken into losing
            told_naomi = kenBlocks[-1] + 0.000000001
            ken_choice = kenBlocks.pop(0)
            for i in range(len(naomiBlocks)):
                if naomiBlocks[i] > ken_choice:
                    naomiBlocks.pop(i)
                    break
            naomiPoints += 1
        else: # we can't actually get anymore points...
            pass

    return naomiPoints

def main():
    gotNumOfTestCases = False
    gotNumBlocks = False
    gotNaomiBlocks = False
    testCases = []
    testCase = []
    for line in fileinput.input():
        if not gotNumOfTestCases:
            numOfTestCases = int(line)
            gotNumOfTestCases = True
        elif not gotNumBlocks:
            testCase.append(int(line))
            gotNumBlocks = True
        elif not gotNaomiBlocks:
            out = line.split()
            for i in range(testCase[0]):
                out[i] = float(out[i])
            testCase.append(out)
            gotNaomiBlocks = True
        else:
            out = line.split()
            for i in range(testCase[0]):
                out[i] = float(out[i])
            testCase.append(out)
            testCases.append(testCase)
            testCase = []
            gotNumBlocks, gotNaomiBlocks = False, False
    for i in range(len(testCases)):
        y, z = process(testCases[i])
        print "Case #%d: %d %d" % (i+1, y, z)

if __name__ == "__main__":
    main()