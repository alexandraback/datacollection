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

def isFair(n):
    s = str(n)
    for i in range(len(s)/2):
        if s[i]!=s[-1-i]:
            return False
    
    return True


def getFairSquareAll(digits):
    ls = []
    for i in range(1,10):
        if isFair(i) and isFair(i**2):
            ls.append(i)
    
    for d in range(2, digits):
        print d
        base = int(math.ceil(d/2.0))
        move = d-base
        for i in range(10**(base-1), 10**base):
            s = str(i)
            for m in range(move-1,-1,-1):
                s = s+s[m]
            s = int(s)
            if isFair(s) and isFair(s**2):
                ls.append(s)
    return ls


#lsFair = getFairSquareAll(15)
#open(r'D:\documents\workspace\snow31450588\python\ez\googleCodeJam\2013\01Qualification\C\dict.txt', 'wb').write(','.join([str(l) for l in lsFair]))

lsFair = [1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001,10011001,10100101,10111101,11000011,11011011,11100111,11111111,20000002,100000001,100010001,100020001,100101001,100111001,100121001,101000101,101010101,101020101,101101101,101111101,110000011,110010011,110020011,110101011,110111011,111000111,111010111,111101111,111111111,200000002,200010002]
print len(lsFair), lsFair

def getFairSmall(a,b):
    for f in xrange(a,b+1):
        if isFair(f):
            yield f

def calc(a,b):
    count = 0
    a = int(math.ceil(math.sqrt(a)))
    b = int(math.floor(math.sqrt(b)))
    for f in getFairSmall(a,b):
        if isFair(f**2):
            count += 1
    return count

def calcBig(a,b):
    global lsFair
    count = 0
    a = int(math.ceil(math.sqrt(a)))
    b = int(math.floor(math.sqrt(b)))
    for l in lsFair:
        if l>b:
            break
        
        if l>=a:
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
        e = calcBig(a,b)
        results.append(e)
    
    wf(fout,results)


if __name__=='__main__':
    fin = sys.argv[1]
    fout = sys.argv[1][:-2]+'out'
    main(fin, fout)
    