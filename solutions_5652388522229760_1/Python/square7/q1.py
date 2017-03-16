import numpy as np
import sys
import string

def decompose(curr):
    lst=[]
    while curr!=0:
        lst.append(curr%10)
        curr=curr/10
    return lst

def fun(i):
    if i==0:
        return False, 0
    d = dict()
    curr = i
    while True:
        for ele in decompose(curr):
            d[ele]=0
        if len(d)==10:
            return True, curr
        curr = curr+i

f=np.genfromtxt(sys.argv[1])[1:]
e = 1
for ln in f:
    print "Case #"+str(e)+": ", 
    ok,res = fun(int(ln))
    if ok:
        print res
    else:
        print "INSOMNIA"
    e=e+1
