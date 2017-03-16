#!/usr/bin/python3
import sys
import os
import traceback
import code
from collections import *
from functools import *

if len(sys.argv) != 2:
    print ('Invalid args')
    sys.exit()
infile = sys.argv[1] 
if infile not in os.listdir('.'):
    print ('file not found!')
    sys.exit()
outfile = infile.replace('.in','.out')

f = open( infile, 'r' )
of = open( outfile, 'w' )

def output( *args, end='\n' ):
    print( ' '.join(map(str, args)), end=end )
    of.write( (' '.join(map(str,args)))+end )

quat = {
    'oo':'o',
    'oi':'i',
    'oj':'j',
    'ok':'k',
    'io':'i',
    'ii':'O',
    'ij':'k',
    'ik':'J',
    'jo':'j',
    'ji':'K',
    'jj':'O',
    'jk':'i',
    'ko':'k',
    'ki':'j',
    'kj':'I',
    'kk':'O'
}

def qt(a,b):
    r = quat[(a+b).lower()]
    if a.isupper() ^ b.isupper():
        return r.swapcase()
    else: return r

def qac(_s):
	c='o'
	for i in range(len(_s)):
		c = qt(c,_s[i])
		yield c

def solCase( case ):
    L,X = list(map( int, f.readline()[:-1].split(' ') ))
    s = f.readline()[:-1]
    if L*X <3:
        output( 'Case #%d: NO'%case )
        return
    olen = len(s)
    prod = reduce( qt, reduce( qt, s )*((X-1)%4+1) )
    if prod != 'O':#ijk muls to -1
        output( 'Case #%d: NO'%case )
        return
    if X>4:
        s = s*4
    else:
        s = s*X

    accum = ''.join([ c for c in qac(s) ])
    try:
        A = accum.index('i')
        ra = list(reversed(accum))
        B = len(ra)-1-ra.index('k')
    except ValueError:
        output( 'Case #%d: NO'%case )
        return
    if X>4: B += (X-4)*olen
    if B+1==L*X or B<=A:
        output( 'Case #%d: NO'%case )
        return
    else:
        output( 'Case #%d: YES'%case )

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
