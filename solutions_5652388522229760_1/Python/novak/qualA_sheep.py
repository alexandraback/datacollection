#!/usr/bin/env python
#
# URL: 
#

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''5
0
1
2
11
1692
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
    num = readone(fhandle)
    logging.info('Test: %d', num)
    return solve(num,params)

def solve(num,params=None):
    if num == 0:
        return 'INSOMNIA'
    arr = {}
    n = num
    while len(arr) < 10:
        _n = n
        while _n > 0:
            arr[_n%10] = None
            _n = _n/10
        n = n + num
    return n-num

if __name__ == '__main__':
    
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('testcases',help='test cases',nargs='?')
    parser.add_argument('-d','--debug',action='count',default=0)
    args = parser.parse_args()

    if args.debug >= 1:
        logging.basicConfig(level=logging.DEBUG,stream=sys.stdout)
    else:
        logging.basicConfig(level=logging.INFO,stream=sys.stdout)

    ifhandle = tempfile.TemporaryFile()
    ifhandle.write(testdata)
    ifhandle.seek(0)
    ofhandle = sys.stdout
    if args.testcases is not None:
        ifhandle = open(args.testcases,'r')
        oname = args.testcases.replace('.in','.out')
        if '.out' not in oname:
            oname = oname + '.out'
        ofhandle = open(oname,'w')

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
