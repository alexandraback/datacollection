#!/usr/bin/env python
#
# URL: https://code.google.com/codejam/contest/6254486/dashboard#s=p3
#

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
'''

def readstr(fhandle):
    return fhandle.readline().strip()

def readone(fhandle):
    return int(fhandle.readline().strip())

def readmult(fhandle):
    return tuple(fhandle.readline().strip().split())

def readmultint(fhandle):
    return tuple(int(x) for x in readmult(fhandle))

def readfirst(fhandle):
    ncases = readone(fhandle)
    return ncases

def nextcase(fhandle,params=None):
    K,C,S = readmultint(fhandle)
    logging.info('Test: %d %d %d', K, C, S)
    return solve(K,C,S)

def solve(K,C,S):
    # K tiles, C complexity, S students
    if K / C > S:
        return 'IMPOSSIBLE'
    arr = []
    i = 0
    while i < K:
        n = 0
        for c in range(C):
            n = K * n + min(i,K-1)
            #print n, i
            i += 1
        arr.append(n+1)
    return ' '.join(str(x) for x in arr)

if __name__ == '__main__':
    
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--test',help='test cases',action='store_true',default=False)
    parser.add_argument('-d','--debug',action='count',default=0)
    args = parser.parse_args()

    if args.debug >= 1:
        logging.basicConfig(level=logging.DEBUG,stream=sys.stdout)
    else:
        logging.basicConfig(level=logging.CRITICAL,stream=sys.stderr)

    ifhandle = sys.stdin
    if args.test:
        ifhandle = tempfile.TemporaryFile()
        ifhandle.write(testdata)
        ifhandle.seek(0)
    ofhandle = sys.stdout

    nparams, ncases = 0, readfirst(ifhandle)

    # parameter reading
    logging.debug('%d parameters', nparams)
    for i in range(nparams):
        pass

    # test case reading
    logging.debug('%d cases', ncases)
    for i in range(ncases):
        ans = nextcase(ifhandle)
        outstr = 'Case #%d: %s' % (i+1, ans)
        logging.info(outstr)
        print >>ofhandle, outstr

    logging.info('Complete')
