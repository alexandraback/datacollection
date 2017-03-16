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

def R(case): output( 'Case #%d: RICHARD'%case )
def G(case): output( 'Case #%d: GABRIEL'%case )

def solCase( case ):
    X,W,H = map( int, f.readline().split(' ') )
    if (W*H)%X: R(case); return#won't fill
    if X>W*H: R(case); return#too big
    if X<=2: G(case); return
    if X>max(W,H):R(case); return#straight
    if X>=7:R(case); return#with hole
    if min(W,H)==1:R(case); return#L shape
    elif min(W,H)==2:
        if X>=4: R(case); return#T or cross
        else: G(case); return
    elif min(W,H)==3:
        if X<=5: G(case); return
        else: R(case); return#x is 6 for big T
    G(case);

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
