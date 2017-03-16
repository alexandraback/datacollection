from __future__ import division
from math import *
from sys import stdout
from fractions import gcd


def get_ints():
    l = map(int,raw_input().split('/'))
    return l

def get_floats():
    l = map(float,raw_input().split())
    return l
        
def func():
    T=int(raw_input())
    pow2=[]
    for i in range(1,41):
    	pow2.append(2**i)
    for cases in range(1,T+1):
        l = get_ints()
        p=l[0]
        q=l[1]
        
        ans = 0

        g=gcd(q,p)
        p=p/g
        q=q/g
        if q not in pow2:
        	print "Case #{0}: impossible".format(cases)
        	continue
        x=p/q
        while x < 0.5:
            ans+=1
            x*=2
        ans+=1
        print "Case #{0}: {1}".format(cases,ans)

func()
