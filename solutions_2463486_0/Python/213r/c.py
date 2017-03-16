import sys
import numpy as np

def read():
    return sys.stdin.readline()

def format(tup):
    return 'Case #%d: %s'%tup

def judge_mirror2(num):
    return str(num) == str(num)[::-1]

ary = []
for i in xrange(1,10**2):
    if judge_mirror2(i):
        num = i * i 
        if judge_mirror2(num): ary.append(num)
    #if judge_mirror(num): print num, '**'
    #else: print num
ary = np.array(ary)
for i in xrange(int(read())):
    a, b = map(int,read().split()) 
    x = ary[a <= ary]
    y = x[x <= b]
    print format((i+1,len(y)))
