# Written in Python 3.3

import math
import sys

def base10(N):
    t=[]
    while (N>0):
        t.append(N%10)
        N=int((N-t[-1])/10)
    return t

def findsol(J,P,S,K):

    cnt = 0

    out = ''
    for ii in range(J):
        if (J>K):
            tmp2 = ii
        else:
            tmp2 = 0
        
        for jj in range(P):
            jpc = 0

            if (P>K):
                tmp = jj
            else:
                tmp = 0
                
            for kk in range(S):
                out += str(ii+1)+str(jj+1)+str(((tmp+tmp2+kk) % S)+1)+'\n'
                cnt += 1
                jpc += 1
                if (jpc >= K):
                    break
            
    out = str(cnt)+'\n'+out
        
    return out

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

fidi = open('C-small-attempt2.in','r')
#fidi = open('Ain.txt','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    N = convertnums(fidi.readline())
    J = N[0]
    P = N[1]
    S = N[2]
    K = N[3]
      
    # Find the solution

    a = findsol(J,P,S,K)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a))
    print('Case #'+str(ii)+': '+str(a))

fidi.close()
fido.close()



