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

def rev(s):
    return ''.join( c for c in reversed(s) )

def solCase( case ):
    n = int( f.readline()[:-1] )
    t = 0
    while n>20:
        s = str(n)
        if s[-1] == '0':
            t+=1
            n-=1
            continue

        if len(s)%2 == 0:
            l = int(rev(s[:(len(s)//2)]))
            t += int(s[(len(s)//2):])+l
            if l>1: t+=1
        else:
            l = int(rev(s[:(len(s)//2)]))
            t +=  l + int(s[(len(s)//2):])
            if l>1: t+=1
        n = int('9'*(len(s)-1))

    t += n
    output( 'Case #%d: %d'%(case,t) )

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
