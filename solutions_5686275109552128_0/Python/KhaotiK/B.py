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
    D = int(f.readline()[:-1])
    line = f.readline()
    print(line)
    P = list(map( int, line[:-1].split(' ') ))
    if D is 0: cost=0
    else: cost = max(P)
    di = {}
    for i in P:
        if i not in di: di[i] = 0
        di[i]+= 1
    ncost = 0
    for pt in range(2,max(di.keys())):
        ncost = pt+sum(((k+pt-1)//pt-1)*v for k,v in di.items() )
        if ncost<cost: cost = ncost
    output( 'Case #%d: %d'%(case,cost) )

for case in range(1,int(f.readline()[:-1])+1):
    try:
        solCase(case)
    except BaseException as e:
        print( e.__class__.__name__+' while solving case %d:'%case )
        traceback.print_tb( sys.exc_info()[2] )
