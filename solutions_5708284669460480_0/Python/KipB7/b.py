#codejam 5/10/2015
import math as m
import time
#import codejam
import sys
import os
sys.setrecursionlimit(100)#1100) #we need 1000 max

cwd = os.getcwd()
filename = cwd+r'\b-test.in.txt'
filename = cwd+r'\B-small-attempt0.in'
#filename = cwd+r'\B-large.in'
#filename = cwd+r'\b-small-practice.in'
foutname = filename.replace(".in",".out")

FILE = open(filename)
FOUT = open(foutname,"w")
T = int(FILE.readline())

def ceildiv(x, d):#like x//d but ceiling, for positives only
    return (x + (d-1)) // d

def alphc(let): #compressed alphabet
    #K2 = sorted(let)
    K3 = {}
    for ch in let:
        if K3.has_key(ch): K3[ch] += 1
        else: K3[ch]=1
    return K3

def sol1(K,L,S,Klet,Llet, dbg):
    """K keys, S keystrokes typed, L target word length"""
    #impossible - we expect 0 and get 0, so keep 0 bananas
    if L>S: return 0,10
    Kh = alphc(Klet) #keyboard letters - get hash of letters and counts
    Lh = alphc(Llet) #desired target word
    p1 = 1.0 #probability we type L if you typed L letters in a row
    for ak in Lh.keys():
        if not Kh.has_key(ak): return 0,20 #can't type it so expect 0 and keep 0 bananas
        p1 = p1 * float(Kh[ak])/K
    #does target word L contain its starting string as an ending subset?
    overlap = 0
    for kl in range(L-1,0,-1): #starts with L-1 ends with 1
        if Llet[:kl] == Llet[-kl:]:
            overlap = kl
            break
    #what is max possible - num of bananas to bring
    if dbg>0: print "overlap: ",overlap, "p1=",p1
    #if word was abcab then we could do abcabcabc to end of S
    if overlap==0:
        maxbananas = S//L
        expected = p1 * maxbananas
    else:
        maxbananas = (S - overlap) // (L - overlap)
        expected = p1 * maxbananas #wild hope out of time
    if dbg: print "maxb=",maxbananas, expected
    return maxbananas - expected,(overlap,maxbananas,expected)
    

dbg=1
if dbg: print ""
if 1:
  t0 = time.time()
  sumz = 0
  for i in range(1,T+1):
    rawline = FILE.readline().split(' ')
    nparams=3
    K,L,S = [int(a) for a in rawline[:nparams]]
    if len(rawline)>nparams: manual_ans = [float(rawline[nparams])]#manual answer
    else: manual_ans = None
    Klet = FILE.readline().strip() #monkey keyboard
    Llet = FILE.readline().strip() #target word
    if dbg: print "Case #" + str(i)+": K,L,S,ans=",K,L,S,Klet,Llet,manual_ans

    z1,codepath = sol1(K,L,S,Klet,Llet, dbg)

    #if dbg: print "  ==> ",z1
    sumz += z1
    msg = 'Case #' + str(i) + ': ' + ("%0.8f"%z1)
    if dbg:
        if manual_ans: print msg+ (" 1 is OK!" if round(manual_ans[0],6)==round(z1,6) else "1 DIFF!") + " Path="+str(codepath)
        else: print msg
    if not dbg and i%10==1: print msg
    FOUT.write(msg + "\n")
    if manual_ans!=None:
        if round(manual_ans[0],6)==round(z1,6): print "...DIFFERENT! ",manual_ans," but we got: ",(z1),"  Case #" + str(i)
    if dbg: print ""
  print "finished",T,"cases,", round(time.time() - t0,3),"s, sumz:",sumz
FOUT.close()
FILE.close()
