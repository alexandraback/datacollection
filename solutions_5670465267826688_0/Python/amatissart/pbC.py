# -*- coding: utf-8 -*-

import sys

def mul(a,b,minus=0):
    res=""
    if a.startswith("-"):
        a=a[1:]
        minus +=1
    if b.startswith("-"):
        b=b[1:]
        minus +=1
    minus = minus %2
    if minus > 0:
        res="-"
    if a=="1":
        return res+b
    elif b=="1":
        return res+a
    elif a==b:
        if res=="":
            return "-1"
        else:
            return "1"
    elif a=="i" and b=="j":
        return res+"k"
    elif a=="j" and b=="k":
        return res+"i"
    elif a=="k" and b=="i":
        return res+"j"
    else:
        return mul(b,a,minus=minus+1)

def muls(s1,s2=[]):
    res = "1"
    for i in s1+s2:
        res = mul(res,i)
    return res

def findProd(s,val,reverse=False):
    res = "1"
    if not reverse:
        for i,e in enumerate(s):
            res = mul(res,e)
            if res==val:
                return i
    else:
        for i,e in enumerate(reversed(s)):
            res = mul(e,res)
            if res==val:
                return i
    return -1

def solve(l,x,s):
    tot = l*x
    nbloc = min(x,4)
    bloc = nbloc*s
    posI = findProd(bloc,"i")
    if posI == -1:
        # print "posI = -1",bloc
        return "NO"
    posK = findProd(bloc,"k",reverse=True)
    if posK == -1 or (posI + posK + 2 >= tot):
        # print "posK?",posI,posK,bloc
        return "NO"
    nBlocsL = posI/l+1
    nBlocsR = posK/l+1
    extraL = (l - posI-1)%l
    extraR = (l - posK-1)%l
    if nBlocsL + nBlocsR >= x:
        nBlocsM =0
    else:
        nBlocsM = (x-nBlocsL - nBlocsR)%4

    if nBlocsL + nBlocsR > x:
        middle = s[-extraL:extraR]
    else:
        left = s[-extraL:]
        right = s[:extraR]
        middle = left + nBlocsM*s + right
    test = muls(middle)
    if test=="j":
        return "YES"
    else:
        return "NO"


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        l,x = tuple(map(int,f.readline().split()))
        s = list(f.readline().strip())
        res = solve(l,x,s)
        print 'Case #%d: %s' % (i+1,res)
        
