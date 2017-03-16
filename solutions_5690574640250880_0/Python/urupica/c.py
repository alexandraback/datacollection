#!/usr/bin/python

import sys, datetime

def solve(r, c, m):
    v = r*c-m
    print 'rows:%d cols:%d mines:%d valid=%d' % (r,c,m,v)
    if v == 1:
        return '\n'.join(['c' + '*'*(c-1)] + ['*'*c for i in xrange(r-1)])
    if r == 1:
        return 'c' + '.'*(v-1) + '*'*m
    if c == 1:
        return '\n'.join(['c'] + ['.']*(v-1) + ['*']*m)
    if min(r, c) == 2:
        if v%2 != 0 or v == 2:
            return 'Impossible'
        if r == 2:
            return '\n'.join(['c' + '.'*(v/2-1) + '*'*(m/2), '.'*(v/2) + '*'*(m/2)])
        return '\n'.join(['c.'] + ['..']*(v/2-1) + ['**']*(m/2))
    if v in (2, 3, 5, 7):
        return 'Impossible'
    l = 0 if v == 4 else 1
    k = 0 if v < 8 else 1
    while 2 + l+1 <= c and 4 + 2*(l+1) + 2*k <= v:
        l += 1
    while 2 + k+1 <= r and 4 + 2*l + 2*(k+1) <= v:
        k += 1
    rows = ['c' + '.'*(1+l) + '*'*(c-2-l), '.'*(2+l) + '*'*(c-2-l)]
    n = 4 + 2*(l+k)
    for i in xrange(k):
        s = '.'*c if n + c-2 <= v else '.'*(2 + v-n) + '*'*(c-2-v+n)
        n += c-2 if n + c-2 <= v else v-n
        rows += [s]
    rows += ['*'*c]*(r-2-k)
    return '\n'.join(rows)



def main():
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()

    try:
        inputFile = open(sys.argv[1])
    except:
        print 'Failed to read input file %s' % sys.argv[1]
        return
    try:
        outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    except:
        print 'Failed to create output file %s' % sys.argv[2]
        return

    testCases = int(inputFile.readline().strip())

    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    for testCaseNumber in range(1, testCases+1):

        r, c, m = map(int, inputFile.readline().strip().split())

        string = 'Case #%d:\n%s' % (testCaseNumber, solve(r, c, m))

        print string
        if outputFile:
            outputFile.write(string + '\n')

    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
