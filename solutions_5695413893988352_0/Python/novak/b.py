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

testdata = '''8
1? 2?
?2? ??3
? ?
?5 ?0
2? 1?
55127??13? 634?31?2?2
?93 20?
????4??1?2???4?2?9 ??3?5?11??????????
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
    str1,str2 = readmult(fhandle)
    logging.info('Test: %s %s', str1, str2)
    return solve(str1,str2)

def solve(s1,s2):
    N = len(s1)
    firsts = [0]
    for i,x in enumerate(s1):
        if x != '?':
            firsts = [10*_s+int(x) for _s in firsts]
            continue
        if s2[i] == '?':
            lets = [0,1,9]
        else:
            lets = [0,1,9,int(s2[i]),((int(s2[i])-1)%10),((int(s2[i])+1)%10)]
        _firsts = []
        for l in lets:
            _firsts = _firsts + [10*_s+l for _s in firsts]
        firsts = sorted(set(_firsts))
    #logging.info(firsts)
    logging.info('%d',len(firsts))
    seconds = [0]
    for i,x in enumerate(s2):
        if x != '?':
            seconds = [10*_s+int(x) for _s in seconds]
            continue
        if s1[i] == '?':
            lets = [0,1,9]
        else:
            lets = [0,1,9,int(s1[i]),((int(s1[i])-1)%10),((int(s1[i])+1)%10)]
        #lets = ['0','1','2','3','4','5','6','7','8','9']
        _seconds = []
        for l in lets:
            _seconds = _seconds + [10*_s+l for _s in seconds]
        seconds = sorted(set(_seconds))
    #logging.info(seconds)
    logging.info('%d',len(seconds))
    firsts = sorted([int(x) for x in firsts])
    seconds = sorted([int(x) for x in seconds])
    min_val = abs(firsts[0]-seconds[0])
    min_arr = [(firsts[0],seconds[0])]
    '''
    for x in firsts:
        for y in seconds:
            if abs(x-y) < min_val:
                min_val = abs(x-y)
                min_arr = []
            if abs(x-y) == min_val:
                min_arr.append((x,y))
    '''
    i = 0
    j = 0
    while i<len(firsts) and j<len(seconds):
        x = firsts[i]
        y = seconds[j]
        if abs(x-y) < min_val:
            min_val = abs(x-y)
            min_arr = []
        if abs(x-y) == min_val:
            min_arr.append((x,y))
        if i == len(firsts):
            j += 1
            continue
        if j == len(seconds):
            i += 1
            continue
        if firsts[i] < seconds[j]:
            i += 1
        else:
            j += 1
            
    logging.info(min_arr)
    min_arr.sort()

    # XXX zero pad
    x,y = min_arr[0]
    x = str(x)
    y = str(y)
    x = '0'*(N-len(x)) + x
    y = '0'*(N-len(y)) + y
    return x,y

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
        x,y = nextcase(ifhandle)
        outstr = 'Case #%d: %s %s' % (i+1, x,y)
        logging.info(outstr)
        print >>ofhandle, outstr

    logging.info('Complete')
