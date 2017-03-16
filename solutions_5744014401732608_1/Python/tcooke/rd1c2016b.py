# Written in Python 3.3

import math
import sys

def base2(N):
    
    t=[]
    while (N>0):
        t.append(N%2)
        N=int((N-t[-1])/2)
    return t

def findsol(B,M):

    # First find a binary representation for M-1

    brep = base2(M-1)

    if (len(brep)+2 > B):
        return 'IMPOSSIBLE'

    # Yes, we can!

    out = 'POSSIBLE\n'

    tmp = '1'
    for ii in brep:
        tmp += str(ii)
    while len(tmp)<B:
        tmp += '0'
    tmp = tmp[::-1]
    tmp = tmp+'\n'

    for jj in range(B-1):
        for kk in range(jj+2):
            tmp += '0'
        for kk in range(jj+2,B):
            tmp += '1'

        if (jj<B-2):
            tmp += '\n'
        
    return out+tmp

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

fidi = open('B-large.in','r')
#fidi = open('Ain.txt','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = convertnums(fidi.readline())
    B = tmp[0]
    M = tmp[1]
      
    # Find the solution

    a = findsol(B,M)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #'+str(ii)+': '+str(a))

fidi.close()
fido.close()



