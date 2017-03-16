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
    C,D,V = map( int ,f.readline()[:-1].split(' ') )
    #C: no more than C coins
    #D: Denoms
    #V: target value
    des = list(map( int ,f.readline()[:-1].split(' ') ))
    vals = {0}
    for v in des:
        vals.update( set( v+i for i in vals ) )
    n = 0
    while True:
        for i in range(V+1):
            if i not in vals:
                n+=1
                vals.update( set( i+j for j in vals ) )
                break
        else: break
    output( 'Case #%d: %d'%(case,n) )

for case in range(1,int(f.readline()[:-1])+1):
    solCase(case)
