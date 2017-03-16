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

testdata = '''3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC
'''

def readstr(fhandle):
    return fhandle.readline().strip()

def readone(fhandle):
    return int(fhandle.readline().strip())

def readint(fhandle):
    return readone(fhandle)

def readmult(fhandle):
    return tuple(fhandle.readline().strip().split())

def readmultint(fhandle):
    return tuple(int(x) for x in readmult(fhandle))

def readfirst(fhandle):
    ncases = readone(fhandle)
    return ncases

def nextcase(fhandle,params=None):
    num = readint(fhandle)
    pairs = [readmult(fhandle) for i in range(num)]
    logging.info('Test: %s', pairs)
    return solve(pairs)

fake_pairs = defaultdict(lambda:0)
def helper(pairs):
    if len(pairs) <= 1:
        return 0
    if tuple(pairs) in fake_pairs:
        return fake_pairs[tuple(pairs)]
    h = defaultdict(lambda:0)
    for (w1,w2) in pairs:
        h[w1,1] += 1
        h[w2,2] += 1
    ret = [0]
    for i,(w1,w2) in enumerate(pairs):
        if h[w1,1] > 1 and h[w2,2] > 1:
            # this pair can be faked
            ret.append(1+helper(pairs[:i]+pairs[i+1:]))
    ret = max(ret)
    fake_pairs[tuple(pairs)] = ret
    return ret

def solve(pairs):
    return helper(sorted(pairs))

if __name__ == '__main__':
    
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--test',help='test cases',action='store_true',default=False)
    parser.add_argument('-d','--debug',action='count',default=0)
    parser.add_argument('inputfile',nargs='?')
    args = parser.parse_args()

    if args.debug >= 1:
        logging.basicConfig(level=logging.DEBUG,stream=sys.stdout)
    else:
        logging.basicConfig(level=logging.CRITICAL,stream=sys.stderr)

    ifhandle = sys.stdin
    if args.inputfile:
        ifhandle = open(args.inputfile)
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
