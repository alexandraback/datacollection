from __future__ import print_function
from pulp import *
from array import *
from scipy.spatial import ConvexHull
import numpy as np
import math
import random
import sys
import argparse
import functools
sys.setrecursionlimit(20000)


debug = False

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

def calc(j,c):
    # out(str(j)+" "+str(c))
    if -1 not in j and -1 not in c:
        return (j,c,abs(int(''.join([str(x) for x in j])) - int(''.join([str(x) for x in c]))))
    m = (None,None,10**19)
    for i in range(len(j)):
        if j[i]==-1 and c[i]!=-1:
            # if c[i]>0:
            #     ans = calc( j[:i] + [c[i]-1] + j[(i+1):], c )
            #     if ans[2] < m[2]:
            #         m = ans
            #
            # ans = calc( j[:i] + [c[i]] + j[(i+1):], c )
            # if ans[2] < m[2]:
            #     m = ans
            #
            # if c[i] < 9:
            #     ans = calc( j[:i] + [c[i]+1] + j[(i+1):], c )
            #     if ans[2] < m[2]:
            #         m = ans
            
            for x in range(0,10):
                ans = calc(j[:i] + [x] + j[(i+1):], c)
                if ans[2] < m[2]:
                    m = ans
            return m
        if j[i]!=-1 and c[i]==-1:
            # if c[i]>0:
            #     ans = calc( j, c[:i] + [j[i]-1] + c[(i+1):] )
            #     if ans[2] < m[2]:
            #         m = ans
            #
            # ans = calc( j, c[:i] + [j[i]] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans
            #
            # if c[i] < 9:
            #     ans = calc( j, c[:i] + [j[i]+1] + c[(i+1):] )
            #     if ans[2] < m[2]:
            #         m = ans

            for x in range(0,10):
                ans = calc( j,  c[:i] + [x] + c[(i+1):] )
                if ans[2] < m[2]:
                    m = ans
            return m
        if j[i]==-1 and c[i]==-1:

            # ans = calc( j[:i] + [0] + j[(i+1):],  c[:i] + [0] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans
            #
            # ans = calc( j[:i] + [0] + j[(i+1):],  c[:i] + [1] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans
            #
            #
            # ans = calc( j[:i] + [1] + j[(i+1):],  c[:i] + [0] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans
            # return m
            #
            # ans = calc( j[:i] + [0] + j[(i+1):],  c[:i] + [9] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans
            # return m
            #
            # ans = calc( j[:i] + [9] + j[(i+1):],  c[:i] + [0] + c[(i+1):] )
            # if ans[2] < m[2]:
            #     m = ans

            for x in range(0,10):
                for y in range(0,10):
                    ans = calc( j[:i] + [x] + j[(i+1):],  c[:i] + [y] + c[(i+1):] )
                    if ans[2] < m[2]:
                        m = ans
            return m
    return m

for t in range(1, T+1):
    out("Case #" + str(t) + ": ",end="")
    s = input().split(' ')
    j = [ x for x in s[0] ]
    c = [ x for x in s[1] ]

    for i in range(0,len(j)):
        if j[i]!='?':
            j[i]=int(j[i])
        else:
            j[i]=-1
        if c[i]!='?':
            c[i]=int(c[i])
        else:
            c[i]=-1

    m = calc(j,c)

    out(''.join([str(x) for x in m[0]])+" "+''.join([str(x) for x in m[1]]))
