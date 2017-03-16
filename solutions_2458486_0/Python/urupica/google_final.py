#!/usr/bin/python

import sys, time

solution = chests = None

def isPossible(keys, chestsLeft):

    keysAvailable = {}
    for k in keys:
        if k not in keysAvailable.keys():
            keysAvailable[k] = 1
        else:
            keysAvailable[k] += 1
    for i in chestsLeft:
        for k in chests[i][1]:
            if k not in keysAvailable.keys():
                keysAvailable[k] = 1
            else:
                keysAvailable[k] += 1
    keysNecessary = {}

    for i in chestsLeft:
        k = chests[i][0]
        if k not in keysNecessary.keys():
            keysNecessary[k] = 1
        else:
            keysNecessary[k] += 1
    for k in keysNecessary.keys():
        if k not in keysAvailable.keys() or keysNecessary[k] > keysAvailable[k]:
            return False

    for i, k in enumerate(chestsLeft):
        necessaryKey = chests[k][0]
        if necessaryKey not in keys:
            found = False
            for j, l in enumerate(chestsLeft):
                if i == j:
                    continue
                if necessaryKey in chests[l][1] and necessaryKey != chests[l][0]:
                    found = True
                    break
            if not found:
                return False

    return True


def check(keys, chestsLeft, opened):
    global solution
    if solution:
        return
    if not chestsLeft:
        solution = opened
        return
    
    keyFirstChest = chests[chestsLeft[0]][0]
    if keyFirstChest in keys and keyFirstChest in chests[chestsLeft[0]][1]:
        keys.remove(keyFirstChest)
        keys += chests[chestsLeft[0]][1]
        opened.append(chestsLeft.pop(0))
        if isPossible(keys, chestsLeft):
            check(keys, chestsLeft, opened)
        return

    for i in chestsLeft:
        for key in keys:
            if chests[i][0] == key:
                keysCopy = keys + chests[i][1]
                keysCopy.remove(key)
                chestsLeftCopy = list(chestsLeft)
                chestsLeftCopy.remove(i)
                if isPossible(keysCopy, chestsLeftCopy):
                    check(keysCopy, chestsLeftCopy, opened + [i])


def solve(keys):
    global solution

    if not isPossible(keys, range(len(chests))):
        return 'IMPOSSIBLE'

    solution = None
    check(keys, range(len(chests)), [])
    if not solution:
        return 'IMPOSSIBLE'
    return ' '.join([str(xx + 1) for xx in solution])

def main():
    global chests
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = time.time()
    inputFile = open(sys.argv[1])
    outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    testCases = int(inputFile.readline().strip())
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if len(sys.argv) < 3:
        print 'No output file'
    print '-----------------'
    for testCaseNumber in range(1, testCases+1):

        k, n = [int(xx) for xx in inputFile.readline().strip().split()]
        keys = [int(xx) for xx in inputFile.readline().strip().split()]
        chests = []
        for i in range(n):
            data = [int(xx) for xx in inputFile.readline().strip().split()]
            chests.append((data[0], data[2:]))

        string = 'Case #%d: %s' % (testCaseNumber, solve(keys))

        print string
        if outputFile:
            outputFile.write(string + '\n')
    print '-----------------'
    if outputFile:
        outputFile.close()
        print 'Written to',sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %.3f seconds' % (time.time()-timestart)
    print '-----------------'

if __name__=='__main__':
    main()
