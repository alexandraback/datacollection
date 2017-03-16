from __future__ import print_function

import time
import sys
import math

def doit(s,D,leng,numSwaps):
    return 




def outP(cNum, st1):
    # print("Case #" + str(cNum) + ": " +str( mNumf)+ "\n")
    # f = open('out','w')

    # print("Case #" + str(cNum) + ": " +str( mNumf), file=f)
    with open('out.txt','a') as oFile:
        oFile.write("Case #" + str(cNum+1) + ": " +str(st1)+"\n")

def stratOne(s):
    W= s[2]
    R = s[0]
    C = s[1]

    res = C%W
    mult = C/W
    if(res>0):
        mult +=1
    turns = (R)*mult +W-1
    turns = (R-1)*C%W+W+C%W

    extra = 0
    if(res>0):
        extra = 1
    if(res>W/2):
        extra = 1
    turns = (C/W)*R+W-1+extra
    # print (str(extra))
    # print (str((C/W)*R))
    # print (str((C/W)))
    # print (str(extra))
    return turns

if __name__ == "__main__":

    file1 = "A-small-attempt1.in"
    # file1 = "in"
    # file1 = "in"
    # file1 = "t1"
    f = open(file1)
    t = int(f.readline())

    tSum = 0
    for _t in xrange(t):
        # lens = int(f.readline())

        s = (f.readline().split())
        s = map(int, s)
        st1 = stratOne(s)
        outP(_t,st1)