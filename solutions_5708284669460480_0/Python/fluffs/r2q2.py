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

def stratOne(s,keys,target):
    keydic = dict()
    tardic = dict()

# find max number of times = numofbananas
# find expected number of times = pop*numofbananas
    K = s[0]
    L = s[1]
    S = s[2]
    if(S<L):
        return 0

    prob = 1.0/float(K)
    # print ("prob")
    # print (str(prob))
    for i in range(K):
        if keys[i] in keydic:
            keydic[keys[i]] += prob
        else:
            keydic[keys[i]] = prob

    for i in range(L):
        if target[i] in tardic:
            tardic[target[i]] += 1
        else:
            tardic[target[i]] = 1

    prob = 1
    probOne = 1
    for k in tardic.keys():
        if(k in keydic):
            probOne *= math.pow(keydic[k],tardic[k])
            # print (k)
            # print (str(keydic[k]))
        else:
            return 0
    mindub = S/L
    exp = 0
    for i in range(int(mindub)):
        fp = (i+1)*(S+1-L)
        exp += math.pow(probOne,(i+1))*(float(fp))
    # print (target)    
    # print (str(L))
    # print (str([mindub]))
    # print (str([probOne]))
    out = mindub-exp
    if(out<0):
        out = 0
    return out

if __name__ == "__main__":

    file1 = "B-small-attempt0.in"
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
        keys = f.readline()
        target = f.readline()
        st1 = stratOne(s,keys,target)
        outP(_t,st1)