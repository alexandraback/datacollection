# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 10:20:28 2016

@author: David
"""
import math
def lowestfac(n):
    for i in range(len(primes)):
        if primes[i] > n**2:
            break
        if n%primes[i] == 0:
            return primes[i]
    return 0
def basento10(n,b):
    t= str(n)
    out = 0
    for i,c in enumerate(t[::-1]):
        out += int(c)*b**i
    return out
    
possibles = range(2,2**8+1)
primes = []

for i in range(2,int(len(possibles)**.5)+1):
    if possibles[i] ==0:
        continue
    for a in range(i**2,int(len(possibles)))[::i]:
        possibles[a] = 0

for p in possibles:
    if p!=0:
        primes.append(p)
        
fin = file("file.in",'r')
fout = file("file.out",'w')
i = int(fin.readline())
for l in range(i):
    n,k = map(int,fin.readline().split())
    count = 0;
    fout.write('Case #%d:\n'%(l+1))
    for j in range(2**n):
        #print j
        if count == k:
            break
        t = bin(j)[2:]
        t = ''.join(['0' for i in range(n-2-len(t))])+t
        #print t
        valid = True
        div = []
        for b in range(2,11):
            num = basento10(int('1'+t+'1'),b)
            lf = lowestfac(num)
            if lf == 0:
                valid = False
                break
            else:
                div.append(lf)
        if valid:
            #print 'ping'
            fout.write('1'+t+'1'+' '+' '.join(map(str,div))+'\n')
            count +=1
    
    
    
    
fin.close()
fout.close()