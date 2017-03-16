#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Phenomics
#
# Created:     10/05/2014
# Copyright:   (c) Phenomics 2014
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import sys
from math import log
from math import ceil

def isValid(x,y):
    if x<y: x,y=y,x;
    if x%y==0: return abs(y);
    return isValid(y,x%y)

def ispower_2(x):
    while x>1:
        if x%2==0: x/=2
        else: return False;
    if x==1: return True;

with open('test_in.in','r') as f:
	data=f.readlines()

N=int(data[0]);
res="";
t=0;

for i in range(N):
    P,Q=[long(_) for _ in data[t+1].split('/')]
    t+=1;
    P,Q=(P/isValid(P,Q),Q/isValid(P,Q));
    if ispower_2(Q):
        k=ceil(-log(P*1.0/Q,2));
        res_t=str(long(k))
    else: res_t="impossible"

    res+="Case #"+str(i+1)+": "+res_t +"\n"

with open('res.txt', 'w') as f:
	f.write(res)
