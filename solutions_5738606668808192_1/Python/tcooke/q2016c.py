# Written in Python 3.3

import math
import sys
import random

def bin2val(b,N):
    r = 0
    for ii in b:
        r = N*r
        if (ii=='1'):
            r += 1
    return r

def convert2bin(N):
    a=''
    while (N>0):
        if (N%2 == 0):
            a='0'+a
        else:
            a='1'+a
        N -= N%2
        N = int(N/2)
    return a

def findsol(L,J):
    out = []
    blen = int((L/2)-2)
    
    if (L%2 == 0) and (J <= 2**blen):
        for ii in range(J):
            b = convert2bin(ii)
            while len(b)<blen:
                b = '0' + b
            b = '1'+b+'1'

            v=[]
            for ii in range(2,11):
                v.append(bin2val(b,ii))
            out.append([b+b,v])
        return out
    else:
        print("Code only works for some starting inputs")
        return []

# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertnums(s):

    a = []
    ii = 0
    for jj in range(len(s)):
        if s[jj]==' ':
            if (ii < jj):
                a.append(int(s[ii:jj]))
                ii = jj + 1
                
    a.append(int(s[ii:jj]))  # No space at end

    return a

# The main code section

fidi = open('C-large.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    
    L = tmp[0]  # Length of JamCoin
    J = tmp[1]  # Number of JamCoins

    # Find the solution

    b = findsol(L,J)
     
    # Show the output

    fido.write('Case #'+str(ii)+':\n')
    for a in b:
        fido.write(a[0]+' ')
        for jj in a[1]:
            fido.write(str(jj)+' ')
        fido.write('\n')
    
    print('Case #'+str(ii))
    for a in b:
        print(a)

fidi.close()
fido.close()

