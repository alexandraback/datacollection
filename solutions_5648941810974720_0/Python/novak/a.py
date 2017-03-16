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

testdata = '''4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER
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
    s = readstr(fhandle)
    logging.info('Test: %s', s)
    return solve(s)

def solve(s):
    zero = s.count('Z')
    two = s.count('W')
    four = s.count('U')
    six = s.count('X')
    eight = s.count('G')
    # need one, three, five, seven, nine
    '''
    count = defaultdict(lambda:0)
    for ch in s:
        count[ch] += 1
    count['Z'] -= zero
    count['R'] -= zero+three+four
    count['O'] -= zero+two+four
    #count['N'] -=
    count['E'] -= zero+three*2+eight
    count['F'] -= four
    '''
    three = s.count('H') - eight
    five = s.count('F') - four
    seven = s.count('S') - six
    one = s.count('O') - zero - two - four
    nine = s.count('E') - zero - three*2 - eight - five - seven*2 - one
    #nine = 0

    logging.debug('%s', [zero,one,two,three,four,five,six,seven,eight,nine])
    logging.debug('%d == %d', one*3+two*3+three*5+four*4+five*4+six*3+seven*5+eight*5+nine*4+zero*4, len(s))
    assert one*3+two*3+three*5+four*4+five*4+six*3+seven*5+eight*5+nine*4+zero*4 == len(s)
    assert min([zero,one,two,three,four,five,six,seven,eight,nine]) >= 0
    return '0'*zero + '1'*one + '2'*two + '3'*three + '4' * four + '5' * five + '6'*six + '7'*seven + '8'*eight + '9'*nine

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
