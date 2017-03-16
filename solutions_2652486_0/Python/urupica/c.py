#!/usr/bin/python

import sys, datetime, itertools

def generateTable():
    table = {}
    for comb in itertools.combinations_with_replacement([2,3,4,5],3):
        table[comb] = {}
        table[comb][1] = 1
        table[comb][comb[0]] = 1
        table[comb][comb[1]] = 1
        table[comb][comb[2]] = 1
        table[comb][comb[0]*comb[1]*comb[2]] = 1
        for comb2 in itertools.combinations_with_replacement(comb, 2):
            x = comb2[0] * comb2[1]
            if x in table[comb].keys():
                table[comb][x] += 1
            else:
                table[comb][x] = 1
    return table

def solve(r, n, m, k, sets):
    table = generateTable()
    answer = []
    for s in sets:
        for comb, dic in table.iteritems():
            if set(s).issubset(set(dic.keys())):
                answer.append(comb)
                break
    st = ''
    for digits in answer:
        st += '\n' + ' '.join(map(str, digits))
    return st

def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()
    inputFile = open(sys.argv[1])
    outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    testCases = int(inputFile.readline().strip())
    print '-----------------'
    print 'Test cases: %d ' % testCases
    if len(sys.argv) < 3:
        print 'No output file'
    print '-----------------'
    for testCaseNumber in range(1, testCases+1):

        r, n, m, k = map(int, inputFile.readline().strip().split())
        sets = []
        for i in range(r):
            sets.append(map(int, inputFile.readline().strip().split()))

        string = 'Case #%d: %s' % (testCaseNumber, solve(r, n, m, k, sets))

        print string
        if outputFile:
            outputFile.write(string + '\n')
    print '-----------------'
    if outputFile:
        outputFile.close()
        print 'Written to',sys.argv[2]
    else:
        print 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

if __name__=='__main__':
    main()
