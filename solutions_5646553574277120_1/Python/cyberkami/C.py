# -*- coding: utf-8 -*-
"""
Created on Sun May 10 19:34:16 2015

@author: cyber
"""

T = int(input())

def ans(C,lis,value):
    if lis==[1]:
        somme_now = 1
        need_now = 0
        while somme_now < value:
            somme_now = somme_now*(C)*(C+1)+C
            need_now+= 1
        return need_now,somme_now
    elif lis == []:
        (need,somme)=ans(C,[1],value)
        return need+1,somme
    else:
        x=lis.pop()
        (need,somme)=ans(C,lis,x-1)
        somme_now = somme+x
        need_now = need
        while somme_now < value:
            somme_now = somme_now*(C)*(C+1)+C
            need_now+= 1
        return need_now,somme_now


def fct():
    (C,D,V) = map(int,input().split())
    lis = list(map(int,input().split()))
    (need,somme)=ans(C,lis,V)    
    print(need)

for test in range(T):
    print ('Case #%d:' % (test+1), end=' ')	
    fct()
