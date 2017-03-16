'''
Created on 27/04/2013

@author: David
'''
from math import pi

def read_data(filename):
    f=open(filename,'r')
    T=int(f.readline().strip())
    data = []
    for _ in range(T):
        R, T =(int(v) for v in f.readline().strip().split())
        data.append((R, T))
    return data

def area1(r):
    return pi*((r+1)*(r+1)-r*r)

def tinta(r,n):
    return (n)*2*r+(n)*(2*(n-1)+1)

def kk(n1, n2, t):
    if n2==n1+1: return n1
    if n2==n1: return n1
    m = (n1+n2)//2
    tt = tinta(r,m)
    if tt<t: return kk(m, n2, t)
    elif tt>t: return kk(n1,m,t)
    else: return m
    
    
def rings(r,t):
    
    n = 1
    while True:
        if tinta(r,n)>t: break
        n *= 2
        #print((r+1)*(r+1)-r*r, 2*r+1)
        #t -= 2*r+1 #(r+1)*(r+1)-r*r
        #if t>=0: num+= 1
        #else: break
        #r+=2
    nMax = n
    nMin = n//2
    return kk(nMin, nMax, t)

   
#data = read_data("A-test.in");
#data = read_data("A-small-attempt0.in");
data = read_data("A-large.in");
f2 = open("resA.txt", "w")
tx = 1
for r,t in data:
    #print(r,t)
    n = rings(r, t)
    cad = "Case #{0}: {1}".format(tx, n)
    print(cad)
    f2.write(cad+"\n")
    tx += 1
f2.close()