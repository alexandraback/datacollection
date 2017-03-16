#!/usr/bin/python

import sys
import copy

def maxline(toys,boxes,h,i):
    m=0
    if i>=len(boxes) or h>=len(toys):
        return 0
    if boxes[i][1]==toys[h][1]:
        tmp = boxes[i][0] - toys[h][0]
        if tmp>0:
            a = tmp
            tmp = boxes[i][0]-tmp
            old = boxes[i][0]
            boxes[i][0]=a
            tmp+=maxline(toys,boxes,h+1,i)
            boxes[i][0]=old
        elif tmp==0:
            tmp = toys[h][0]+tmp
            tmp+=maxline(toys,boxes,h+1,i+1)
        else:
            a = -tmp
            tmp = toys[h][0]+tmp
            old=toys[h][0]
            toys[h][0]=a
            tmp+=maxline(toys,boxes,h,i+1)
            toys[h][0]=old
        m=tmp
    else:
        a = maxline(toys,boxes,h+1,i)
        b = maxline(toys,boxes,h,i+1)
        if a>b:
            m=a
        else:
            m=b
    return m

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    N,M = map(int,sys.stdin.readline().rstrip().split(' '))
    oboxes = map(int,sys.stdin.readline().rstrip().split(' '))
    boxes = []
    b1 = []
    for i in range(0,len(oboxes),2):
        boxes.append([oboxes[i],oboxes[i+1]])
        b1.append(oboxes[i+1])
    otoys = map(int,sys.stdin.readline().rstrip().split(' '))
    toys = []
    for i in range(0,len(otoys),2):
        if otoys[i+1] in b1:
            toys.append([otoys[i],otoys[i+1]])
    w=0
    for j in range(0,len(toys)):
        m=maxline(toys,boxes,j,0)
        if m>w:
            w=m
    print "Case #"+str(case)+": "+str(w)
