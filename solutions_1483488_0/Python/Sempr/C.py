import sys
import logging

tot=[]
def calc(low,high):
    c = 0
    used = set()
    for i in xrange(low,high+1):
        if i %10000 == 0: logging.warning("%s%d%s","-"*10,i,"*"*10)
        if i in used: continue
        ss=str(i)
        L = len(ss)
        vs = [int(ss[i:]+ss[:i]) for i in xrange(L) if ss[i]!='0']
#        print vs
        vss = set([x for x in vs if x>=low and x<=high])
        used |= vss
        vs = sorted(list(vss))
        L = len(vs)
        tot.extend([(vs[a],vs[b]) for a in xrange(0,L) for b in xrange(a+1,L)])
    L = len(tot)
    return tot 
L = 0

tot = calc(1,20000)
L = len(tot)

def count(low,high):
#    print low,high,L
    rc = 0
    for i in xrange(0,L):
        a,b=tot[i]
        if a>=low and b<=high: rc+=1
    return rc

f=open(sys.argv[1],'r')
ss = f.readlines()
N = int(ss[0])

for i, s in enumerate(ss):
    if i==0: continue
    if i>N: break
    a,b = s.split()[:2]
    a = int(a)
    b = int(b)
    print "Case #%d: %d"%(i,count(a,b))
