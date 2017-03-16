f=open("input")
ff=open("output", "w")
readint=lambda :int(f.readline())
readintarray=lambda :map(int, f.readline().split())
T=readint()
axx=[[0], [1,2,3]]
revnum = lambda num: int("".join(reversed(str(num))))
revnumx = lambda num,d: int("".join(reversed("%0*d"%(d,num))))
for n in range(2,8):
    tmp=[]
    for x in axx[-1]:
        x=x*10
        M=10**n
        for d in range(10):
            num=x+d
            rev=revnum(num)
            sq=num**2*10/M
            sq2=(num+1)**2*10/M
            revsq=revnumx(rev**2%M, n)
            if sq<=revsq<sq2:
                tmp.append(num)        
                #print "yes"
            #print x,num,rev, (sq,sq2), revsq
    #print n,tmp
    axx.append(tmp)
def isqrt(n):
    x = n
    y = (x + n / x) / 2
    while y < x:
        x = y
        y = (x + n / x) / 2
    return x

#very safe method
def very_safe(a, b):
    rtn=[]
    start=isqrt(a)
    end=isqrt(b)+1
    for num in range(start, end):
        if num==revnum(num):
            sq=num**2
            if sq==revnum(sq) and a<=sq<b:
                rtn.append(num)
    return rtn


def safe(a,b):
    rtn=[]
    a2,b2 = isqrt(a), isqrt(b)+1
    #print "a2,b2", a2,b2
    a2s,b2s=str(a2),str(b2)
    if len(a2s)==1:
        start=0
    else:
        start=10**(len(a2s)/2-1)
    end=10**(len(b2s)/2)
    shift=10**len(str(start))
    for num in range(start,end):
        rnum=revnum(num)
        if num==shift:
            shift*=10
        for mid in [""]+list(range(10)):
            if num==0:
                if mid=="":
                    continue
                pnum=mid
            elif mid=="":
                pnum=num*shift+rnum
            else:
                pnum=(num*10+mid)*shift+rnum
            sq=pnum**2
            if sq==revnum(sq) and a<=sq<b:
                rtn.append(pnum)
    return rtn

def realone(a,b):
    rtn=[]
    a2,b2 = isqrt(a), isqrt(b)+1
    #print "a2,b2", a2,b2
    a2s,b2s=str(a2),str(b2)
    sidx=len(a2s)/2
    eidx=len(b2s)/2+1
    for idx in range(sidx,eidx):
        shift=10**idx
        for num in axx[idx]:
            rnum=revnum(num)
            for mid in [""]+list(range(10)):
                if num==0:
                    if mid=="":
                        continue
                    pnum=mid
                elif mid=="":
                    pnum=num*shift+rnum
                else:
                    pnum=(num*10+mid)*shift+rnum
                sq=pnum**2
                if sq==revnum(sq) and a<=sq<b:
                    rtn.append(pnum)
    return rtn

"""
import time
t0=time.time()
print "a"
r1=sorted(realone(1,10**12))
t1=time.time()
print "b", t1-t0
r2=sorted(very_safe(1,10**12))
t2=time.time()
print "c", t2-t1
print r1
print r2
print r1==r2        
"""

for casex in range(1,T+1):
    a,b=readintarray()
    result=realone(a,b+1)
    print >>ff, "Case #%d:"%casex, len(result)
    
ff.close()
