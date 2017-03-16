#!/usr/bin/env python
#
# URL: https://code.google.com/codejam/contest/6254486/dashboard#s=p2
#

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''1
8 3
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
    n,j = readmultint(fhandle)
    logging.info('Test: %d %d', n, j)
    return solve(n,j)

def solve(N,J):
    # need J solutions of length N
    ans = ''
    for x in range(J):
        factors = [i**(N/2-1)+1 for i in range(11)]
        y = x
        j = 1
        while y > 0:
            #print y
            for i in range(11):
                factors[i] = factors[i] + (y%2)*(i**j)
            y = y/2
            j = j+1
        val = factors[-1] * (10**(N/2)+1)
        #print x, factors
        ans = ans + '\n%d'%val + ' %d'*9 % tuple(factors[2:])

        for i in range(2,11):
            assert int(str(val),i) % factors[i] == 0
        
    return ans

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
