# -*- coding: utf-8 -*-
"""
Created on Sun May 10 20:12:13 2015

@author: cyber
"""
T = int(input())

def ram(chaine,lon):
    ii = len(chaine)
    for i in range(1,len(chaine)):
        flag = True
        for j in range(i,len(chaine)):
            if chaine[j]!=chaine[j-i]:
                flag = False
        if flag == True:
            ii = i
            break
    return (lon-len(chaine))//ii+1
            

def fct():
    (K,L,S) = map(int,input().split())                
    L1 = input()
    L2 = input()
    dic = dict()
    for x in L1:
        if x in dic:
            dic[x]+=1
        else:
            dic[x]=1
    mul = 1
    for x in L2:
        if x not in dic:
            mul = 0
        else:
            mul*=dic[x]/len(L1)
    pro = mul*(L-len(L1)+1)
    ra = ram(L2,S)
    print(pro/ra)

for test in range(T):
    print ('Case #%d:' % (test+1), end=' ')	
    fct()




