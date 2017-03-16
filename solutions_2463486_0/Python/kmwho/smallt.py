#! /bin/python
#  LeLouch16 CodeJam '13 Qualification Round

import sys
from math import *

if len(sys.argv) < 3:
    print "Not enough arguments"
    print "Usage '%s input.in output.out'" % sys.argv[0]
    sys.exit()

inpf  = sys.argv[1]
outf  = sys.argv[2]

fin   = sys.stdin if inpf == '-' else open(inpf)
fout  = sys.stdout if outf == '-' else open(outf,'w')

debug = False

T = int(fin.readline().strip())
if debug: print "Number of test Cases:",T

######################

lim   = 10**4
pals  = []
total = 0

def checkpal(n):
    s = str(n)
    return s == s[::-1]

for i in xrange(1, int(sqrt(lim))+1):
    if checkpal(i) and checkpal(i**2):
        pals.append(i**2)
        total += 1

if debug: print pals

def count(A,B):
    j   = 0
    cA  = 0
    while j < total:
        if pals[j] >= A:
            break
        j += 1
    cA  = j
    cB  = j
    while j < total:
        if pals[j] > B:
            break
        j += 1
    cB  = j
    return cB - cA
    
    

for tc in range(T):
    A,B = [int(c) for c in fin.readline().strip().split()]
    r   = str(count(A,B))
    s = 'Case #'+str(tc+1)+': '+r
    fout.write(s+'\n')
    if debug: print s, 'for', A,B


fin.close()
fout.close()
