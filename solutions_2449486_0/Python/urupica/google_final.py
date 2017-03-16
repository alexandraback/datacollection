#!/usr/bin/python

import sys, time

lawnTarget = None
possible = None

def solve(n, m, unfinished):
    global possible
    if possible:
        return
    if not unfinished:
        possible = True
        return

    minHeight = 100
    for (i,j) in unfinished:
        if lawnTarget[i][j] < minHeight:
            minHeight = lawnTarget[i][j]
    ind = range(len(unfinished))
    ind.sort(key=lambda k: lawnTarget[unfinished[k][0]][unfinished[k][1]])
    minHeightSquares = []
    for k in ind:
        (i,j) = unfinished[k]
        if lawnTarget[i][j] == minHeight:
            minHeightSquares.append((i,j))
        else:
            break

    rowAndOrCol = [0]*len(minHeightSquares)
    for k, (i, j) in enumerate(minHeightSquares):
        testRow = testCol = True
        for ii in range(n):
            if lawnTarget[ii][j] > minHeight:
                testCol = False
                break
        if testCol:
            rowAndOrCol[k] += 1
        for jj in range(m):
            if lawnTarget[i][jj] > minHeight:
                testRow = False
                break
        if testRow:
            rowAndOrCol[k] += 2

        if not testRow and not testCol:
            return

    if 1 in rowAndOrCol:
        (i,j) = unfinished.pop(ind[rowAndOrCol.index(1)])
        for ii in range(n):
            if (ii,j) in unfinished:
                unfinished.remove((ii,j))
        solve(n, m, unfinished)
    elif 2 in rowAndOrCol:
        (i,j) = unfinished.pop(ind[rowAndOrCol.index(2)])
        for jj in range(m):
            if (i,jj) in unfinished:
                unfinished.remove((i,jj))
        solve(n, m, unfinished)
    else:
        (i,j) = unfinished.pop(ind[rowAndOrCol.index(3)])
        unfinishedCopyCol = [tuple(coord) for coord in unfinished]
        for ii in range(n):
            if (ii,j) in unfinishedCopyCol:
                unfinishedCopyCol.remove((ii,j))
        unfinishedCopyRow = [tuple(coord) for coord in unfinished]
        for jj in range(m):
            if (i,jj) in unfinishedCopyRow:
                unfinishedCopyRow.remove((i,jj))
        solve(n, m, unfinishedCopyRow)
        solve(n, m, unfinishedCopyCol)


def main():
    global lawnTarget, possible
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

        n, m = [int(xx) for xx in inputFile.readline().strip().split()]
        lawnTarget = []
        for i in range(n):
            lawnTarget.append([int(xx) for xx in inputFile.readline().strip().split()])
        unfinished = []
        for i in range(n):
            for j in range(m):
                if lawnTarget[i][j] != 100:
                    unfinished.append((i,j))
        possible = False
        solve(n, m, unfinished)
        string = 'Case #%d: %s' % (testCaseNumber, 'YES' if possible else 'NO')

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
