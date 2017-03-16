from __future__ import print_function
from pulp import *
from array import *
from scipy.spatial import ConvexHull
import numpy as np
import math
import random
import sys
import argparse

debug = True

def pr(s,end=None):
    if debug==True:
        if end!=None:
            print(s,end=end,flush=True, file=sys.stderr)
        else:
            print(s,flush=True, file=sys.stderr)

def out(s,end=None):
    if end!=None:
        print(s,end=end,flush=True)
    else:
        print(s,flush=True)

T = int(input())

def rem(s,d):
    for c in d:
        i = s.find(c)
        if i>=0:
            s = s[:i] + s[i+1:]
        else:
            return None
    return s

for t in range(1, T+1):
    out("Case #" + str(t) + ": ",end="")
    s = input()
    f = {}
    ds = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    digits = {"ZERO":0,"ONE":1,"TWO":2, "THREE":3, "FOUR":4, "FIVE":5, "SIX":6, "SEVEN":7, "EIGHT":8, "NINE":9}
    for d in ["ZERO", "TWO", "FOUR", "SIX", "EIGHT", "SEVEN",  "FIVE","THREE", "ONE", "NINE"]:
        count = 0
        while True:
            s2 = rem(''+s,d)
            if s2 == None:
                break
            else:
                count+=1
                s = s2
        f[d] = count
    if s!='':
        pr(s)

    for d in ds:
        if d in f:
            for i in range(0,f[d]):
                out(digits[d],'')
    out('')
