#!/usr/bin/env python

import sys

infile=open(sys.argv[1])

def radius(x,y):
    return x*x+y*y

def sqdist(p,q):
    return radius(p[0]-q[0],p[1]-q[1])

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

def norm(a,b):
    g=abs(gcd(a,b))
    return (a//g,b//g)

def solve(H,W,D,map):
    #print H,W,D,'\n','\n'.join(map)
    for Y,col in enumerate(map):
        X=col.find('X')
        if X != -1:
            break
    #print X,Y
    
    H=H-2
    W=W-2
    X=X-1
    Y=Y-1
    
    phantom=set()
    for i in range(-(D//W+1), (D//W+2)):
        if i%2 == 0:
            s=W*i+X
        else:
            s=W*i+(W-X-1)
        for j in range(-(D//H+1), (D//H+2)):
            if j%2 == 0:
                t=H*j+Y
            else:
                t=H*j+(H-Y-1)
            #print (i,j),(s,t),
            if (s-X,t-Y) != (0,0) and radius(s-X,t-Y) <= D*D:
                #print '*'
                phantom.add(norm(s-X,t-Y))
            #else:
            #    print ''
    return len(phantom)
    
mapline=0
casenum=0
for n,line in enumerate(infile):
    if n==0:
        T=int(line)
        continue
    if mapline==0:
        H,W,D=[int(x) for x in line.split()]
        mapline=H
        map=[]
    else:
        map.append(line.strip())
        mapline-=1
        if mapline==0:
            casenum+=1
            ans=solve(H,W,D,map)
            print "Case #%d: %d" % (casenum,ans)

