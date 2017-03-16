import math
#from codejamlib import *

filename = r'A-test.txt'
filename = r'A-small-attempt0.in'
#filename = 'A-large.in'
foutname = r'A-out.txt'

FILE = open(filename,"r")
FOUT = open(foutname,"w")
T = int(FILE.readline())
dbg=1
cons = [(ch not in 'aeiou')&1 for ch in 'abcdefghijklmnopqrstuvwxyz']

def docase(wd,n):
    cn = [cons[ord(ch) - ord('a')] for ch in wd] #which letters consonants
    nconst_start = []
    consec = 0
    for p,isc in enumerate(cn):
        if isc: consec += 1
        else: consec = 0
        if consec>=n: nconst_start.append(p-n+1)

    next_start = 0
    ct = 0 #count of substrings
    if dbg: print cn, len(wd), n, nconst_start
    for cst in nconst_start:
        #how many substrings start from next_start and end at end of word
        #and contain from cst to cst+n-1
        let_before = cst - next_start
        let_after = len(wd) - cst - n
        new_subst = (let_before+1) * (let_after+1)
        if dbg: print "found: const="+wd[cst:cst+n],"pos=",cst,"let b4=",let_before,"aft=",let_after," score+=",new_subst
        ct += new_subst
        next_start = cst+1
    return [ct]

if 1:
  dbg=0
  for caseno in range(1,T+1):
    rawline = FILE.readline()
    if caseno>0:
        if dbg: print "Case #" + str(caseno)+": begin " + repr(rawline)
        wd,ns = rawline.split(' ')
        n=int(ns)
        rets = docase(wd,n)
        msg = 'Case #' + str(caseno) + ': ' + ("%d"%rets[0])
        if caseno<=100: print msg," input=",rawline
        FOUT.write(msg + "\n")
        if dbg: print ""
FOUT.close()
