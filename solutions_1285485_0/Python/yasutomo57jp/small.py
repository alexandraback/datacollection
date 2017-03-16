#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool

def peal(lines):
    result=lines
    result.pop(0)
    result.pop()
    for l in result:
        l.pop(0)
        l.pop()
    return result, len(result[0]), len(result)

def rotate(lines,px,py):
    result=[[0 for y in lines] for x in lines[0]]
    h=len(lines)
    for y, l in enumerate(lines):
        for x, p in enumerate(l):
            result[x][h-y-1]=p
    return result, len(lines), len(lines[0]), h-py-1, px

def mirror_x(lines):
    return [[p for p in reversed(l)] for l in lines]

def mirror_y(lines):
    return [[p for p in l] for l in reversed(lines)]

def append_x(a,b):
    w=len(a[0])
    result=[[ 0 for x in range(len(a[0])+len(b[0]))] for y in a]
    for y,l in enumerate(a):
        for x,p in enumerate(l):
            result[y][x]=p
    for y,l in enumerate(b):
        for x,p in enumerate(l):
            result[y][x+w]=b
    return result

def append_y(a,b):
    h=len(a)
    result=[]
    for l in a:
        result.append(l)
    for l in b:
        result.append(l)
    return result

def dist1(w,x):
    return (w-x-0.5)*2

def dist2(w,h,x,y,u,v):
    xlen=0
    ylen=0
    if u%2==0:
        xlen=2*(x+0.5)+(u-2)*w
    else:
        xlen=(u-1)*w

    if v%2==0:
        ylen=2*(y+0.5)+(v-2)*h
    else:
        ylen=(v-1)*h

    return math.sqrt(ylen**2+xlen**2),float(ylen)/float(xlen)

def f(q):
    #print "====="
    h,w,d,lines=q

    findflag=False
    px=py=0
    for y,l in enumerate(lines):
        for x,p in enumerate(l):
            if p == "X":
                px=x
                py=y
                findflag=True
                break
        if findflag: break

    result=0
    ilines,iw,ih=peal(lines)
    ipx=px-1
    ipy=py-1

    for t in range(4):
        d1=dist1(iw,ipx)
        if d1>d: continue
        result+=1

        u=2
        angles=set([])
        while True:
            v=2
            d2,angle=dist2(iw,ih,ipx,ipy,u,v)
            if d2>d:break
            if not angle in angles:
                result+=1
                angles.add(angle)
            while True:
                v+=1
                d2,angle=dist2(iw,ih,ipx,ipy,u,v)
                if d2>d: break
                if not angle in angles:
                    result+=1
                    angles.add(angle)
            u+=1

        ilines,iw,ih,ipx,ipy=rotate(ilines,ipx,ipy)
        #print iw, ih, ipx, ipy


    return str(result)

lines=int(sys.stdin.readline().strip())
q=[]
for i in range(lines):
    h,w,d=map(int,sys.stdin.readline().strip().split(" "))
    lines=[]
    for y in range(h):
        lines.append(list(sys.stdin.readline().strip()))

    q.append([h,w,d,lines])

p=Pool(8)
result=p.map(f, q)
#result=map(f,q)

for i,r in enumerate(result):
    print "Case #%d: %s" % (i+1, r)

