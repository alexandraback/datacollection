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


def solCase( case ):
    S, slist = f.readline()[:-1].split(' ')
    S = eval(S)
    slist = map( int, slist )
    inc=0
    s=0
    for si, sval in enumerate(slist):
        if sval == 0: continue
        if s<si:
            inc+=si-s
            s=si
        s += sval
    output( 'Case #%d: %d'%(case,inc) )
 

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
