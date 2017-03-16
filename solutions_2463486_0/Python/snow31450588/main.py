#!/usr/bin/env python
#encoding=utf-8

'''
author:     Eric Zhang(snow31450588@gmail.com)
date:       2013-04-13
purpose:    Google Code Jam Qualification Round
history:
    2013-04-13  Initial version
'''

import sys
import math


def getFailAll(b):
    pass

def getFairBig(a,b):
    for f in xrange(a,b+1):
        if isFair(f):
            yield f


def getFairSmall(a,b):
    for f in xrange(a,b+1):
        if isFair(f):
            yield f

def isFair(n):
    s = str(n)
    for i in range(len(s)/2):
        if s[i]!=s[-1-i]:
            return False
    
    return True

def calc(a,b):
    count = 0
    a = int(math.ceil(math.sqrt(a)))
    b = int(math.floor(math.sqrt(b)))
    for f in getFairSmall(a,b):
        if isFair(f**2):
            count += 1
    return count

def wf(fileName,results):
    f = open(fileName,'w')
    for i,r in enumerate(results):
        f.write('Case #%d: %s\n'%(i+1,r))
    f.close()

def rf(fileName):
    f = open(fileName,'r')
    inputs = []
    n = int(f.readline())
    for i in range(n):
        a,b = f.readline().strip().split()
        inputs.append((int(a),int(b)))
    return inputs

def main(fin, fout):
    results = []
    
    for a,b in rf(fin):
        e = calc(a,b)
        results.append(e)
    
    wf(fout,results)


if __name__=='__main__':
    fin = sys.argv[1]
    fout = sys.argv[1][:-2]+'out'
    main(fin, fout)
    