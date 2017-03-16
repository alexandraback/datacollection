#!/usr/bin/python

import math
fi=open('B-large.in','r')

n=int(fi.readline())
for k in range(1,n+1):
    c,f,x=[float(x) for x in fi.readline().split()]
    #print(c,f,x)
    s,t=f*(x-c)/c,0 # x/s = c/s + x/(s+f)
    #print('s=',s)
    if s>=2:
        p=math.ceil((s-2)/f)
        #print('p=',p)
        for i in range(p):
            t+=c/(2+i*f)
            #print(t,end=' ')
        t+=x/(2+f*p)
        #print(t)
    else:
        t+=x/2
    print("Case #%d: %f"%(k,t))
