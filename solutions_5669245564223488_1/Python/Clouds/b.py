#!/usr/bin/python

import sys
import math
fin=sys.stdin
T=int(fin.readline())

for kk in range(T):
    imp,ans=False,1
    n=int(fin.readline())
    a=fin.readline().split()
    s=[(set(x),ord(x[0])-ord('a'),ord(x[-1])-ord('a')) for x in a]
    d,e=[0]*26,[-1]*26
    for i in range(n):
        for j in range(n):
            if i!=j:
                ss=s[i][0]&s[j][0]
                if len(ss)>1:
                    imp=True
                elif len(ss)==1:
                    ss=ss.pop()
                    if not((ss==a[i][-1] and ss==a[j][0]) or (ss==a[i][0] and ss==a[j][-1])):
                        #print(ss,s[i],s[j],imp)
                        imp=True
    used=[-1]*26
    for i in range(n):
        #print(s[i])
        k=1
        for j in range(len(a[i])-1):
            if a[i][j]!=a[i][j+1]:
                k+=1
        if len(s[i][0])!=k:
            imp=True
        elif s[i][1]==s[i][2]:
            d[s[i][1]]+=1
        elif e[s[i][1]]==-1:
            e[s[i][1]]=s[i][2]
        else:
            imp=True
        used[s[i][1]]=0
    #print(used)
    k=0
    for i in range(26):
        if imp:
            break
        if used[i]==0:
            used[i]=-2
            j=i
            k+=1
            while e[j]!=-1:
                j=e[j]
                if used[j]==1:
                    #print(used,i,j,imp)
                    imp=True
                    break
                elif used[j]==-2:
                    used[j]=1
                    k-=1
                    break
                else:
                    used[j]=1
    #print(used)
    #print(k,d,e)
    if imp:
        print("Case #%d: 0"%(kk+1))
    else:
        ans=math.factorial(k)
        #print(k)
        for i in range(26):
            ans*=math.factorial(d[i])
        print("Case #%d: %d"%(kk+1,ans%(10**9+7)))

