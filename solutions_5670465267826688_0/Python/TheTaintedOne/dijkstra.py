import sys
import itertools
import numpy as np
from collections import defaultdict
import time


mapping = dict()
mapping = {("_","_"): ("_", 1), ("_","i"): ("i",  1), ("_","j"): ("j",  1), ("_","k"): ("k",  1),
           ("i","_"): ("i", 1), ("i","i"): ("_", -1), ("i","j"): ("k",  1), ("i","k"): ("j", -1),
           ("j","_"): ("j", 1), ("j","i"): ("k", -1), ("j","j"): ("_", -1), ("j","k"): ("i",  1),
           ("k","_"): ("k", 1), ("k","i"): ("j",  1), ("k","j"): ("i", -1), ("k","k"): ("_", -1)}
# print mapping


def mult(A, B):
    res = mapping[(A[0],B[0])]
    return (res[0], A[1]*B[1]*res[1])


def reducePattern(line):
    source = ("_",1)
    for v in line:
        source = mult(source,(v,1))
    return source


def findSplitPoint(line, target):
    leftInput = ""
    source = ("_",1)
    for i,v in enumerate(line):
        source = mult(source,(v,1))
        leftInput += v
        if source==(target,1):
            return leftInput,str(line[i+1:]),True
    return "","",False


lines = sys.stdin.readlines()

ntests = int(lines[0])

curr = 1
for t in range(1, ntests+1):
    L, X = [int(x) for x in lines[curr+0].strip().split(" ")]
    pattern = lines[curr+1].strip()
    inputs = pattern*X
    # print reducePattern(pattern)

    success = False
    initSuccess = (reducePattern(pattern*X)==("_",-1))
    ipart = ("_",1)
    if initSuccess:
        for i in xrange(L*X):
            ipart = mult(ipart,(inputs[i],1))
            if ipart==("i",1):
                jpart = ("_",1)
                for j in xrange(i+1,L*X):
                    jpart = mult(jpart,(inputs[j],1))
                    if jpart==("j",1):
                        kpart = ("_",1)
                        for k in xrange(j+1,L*X):
                            kpart = mult(kpart,(inputs[k],1))
                        success = (kpart==("k",1))
                    if success:
                        break
            if success:
                break


    if success:
        print "Case #"+ str(t) + ": YES"
    else:
        print "Case #"+ str(t) + ": NO"
    # print "\n\n\n"

    curr += 2
