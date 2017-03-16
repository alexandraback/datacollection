#codejam 5/10/2015
import math as m
import time
#import codejam
import sys
import os
sys.setrecursionlimit(100)#1100) #we need 1000 max

cwd = os.getcwd()
filename = cwd+r'\a-test.in.txt'
filename = cwd+r'\A-small-attempt0.in'
filename = cwd+r'\A-large.in'
#filename = cwd+r'\a-small-practice.in'
foutname = filename.replace(".in",".out")

FILE = open(filename)
FOUT = open(foutname,"w")
T = int(FILE.readline())

def ceildiv(x, d):#like x//d but ceiling, for positives only
    return (x + (d-1)) // d

def sol1(R,C,W, dbg):
    #top R-1 rows
    TR = (R-1) * (C//W)
    #last row
    LR1 = (C//W) # last one is always a hit
    LR2 = 1 if C%W>0 else 0 #a miss just to left of ship
    LR3 = W-1 #remaining spots on ship
    return TR+LR1+LR2+LR3, (TR,LR1,LR2,LR3)
    #answer and path to answer

dbg=0
if dbg: print ""
if 1:
  t0 = time.time()
  sumz = 0
  for i in range(1,T+1):
    rawline = FILE.readline().split(' ')
    nparams=3
    R,C,W = [int(a) for a in rawline[:nparams]]
    if len(rawline)>nparams: manual_ans = [int(rawline[nparams])]#manual answer
    else: manual_ans = None
    
    if dbg: print "Case #" + str(i)+": R,C,W,ans=",R,C,W,manual_ans

    z1,codepath = sol1(R,C,W, dbg)

    #if dbg: print "  ==> ",z1
    sumz += z1
    msg = 'Case #' + str(i) + ': ' + str(z1)
    if dbg:
        if manual_ans: print msg+ (" 1 is OK!" if manual_ans[0]==z1 else "1 DIFF!") + " Path="+str(codepath)
        else: print msg
    if not dbg and i%10==1: print msg
    FOUT.write(msg + "\n")
    if manual_ans!=None:
        if manual_ans[0]!=z1: print "...DIFFERENT! ",manual_ans," but we got: ",(z1),"  Case #" + str(i)
    if dbg: print ""
  print "finished",T,"cases,", round(time.time() - t0,3),"s, sumz:",sumz
FOUT.close()
FILE.close()
