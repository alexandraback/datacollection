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
    K, L, S = map( int, f.readline()[:-1].split(' ') )
    #L: len of target
    #S: len gonna type
    keys = f.readline()[:-1]
    keys_c = Counter()
    keys_c.update( keys )
    target = f.readline()[:-1]
    target_c = Counter()
    target_c.update(target)
    if (len(set(target_c.keys()).difference( set(keys_c.keys()) )) != 0) or L>S:
        output( 'Case #%d: 0.0'%case )
        return
    tot = K**S
    cnt_e = 0
    cnt_m = 0
    for i in range(tot):
        s = [' ']*S
        ii = i
        for j in range(S):
            ii, k = divmod(ii,K)
            s[j] = keys[k]
        acnt = 0
        ss = ''.join(s)
        for j in range(S-L+1):
            if ss[j:j+L] == target: acnt += 1
        cnt_e += acnt
        if acnt > cnt_m: cnt_m = acnt
    e = cnt_m - (cnt_e/tot)
    output( 'Case #%d: %f'%(case, e ) )

        

for case in range(1,int(f.readline()[:-1])+1):
    #try:
    #    solCase(case)
    #except BaseException as e:
    #    print( e.__class__.__name__+' while solving case %d:'%case )
    #    traceback.print_tb( sys.exc_info()[2] )
    solCase( case )
