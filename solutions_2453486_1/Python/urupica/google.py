#!/usr/bin/python

import sys, time

def solve(board):
    finished = True
    for row in board:
        if '.' in row:
            finished = False
            break

    lines = [list(row) for row in board]
    for j in range(4):
        lines.append([board[i][j] for i in range(4)])
    lines.append([board[i][i] for i in range(4)])
    lines.append([board[i][3-i] for i in range(4)])

    for p in ['O', 'X']:
        for l in lines:
            if l.count(p) == 4 or l.count(p) == 3 and 'T' in l:
                return p + ' won'

    if finished:
        return 'Draw'
    return 'Game has not completed'


def main():
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
        rows = []
        for i in range(4):
            rows.append(inputFile.readline().strip())
        inputFile.readline()

        string = 'Case #%d: %s' % (testCaseNumber, solve(rows))

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
