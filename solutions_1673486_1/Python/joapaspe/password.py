#!/usr/bin/env python


import sys


if __name__ == '__main__':
    ncases = int(sys.stdin.readline())

    for nc in range(ncases):
        fields = sys.stdin.readline().split()
        A = int(fields[0])
        B = int(fields[1])

        prob = [float(f) for f in sys.stdin.readline().split()]

        #Compute probabilities
        
        mistakes = 0
        #Rule 1
        cprob = [0]*A
        acum = 1
        for i in range(A):
            acum*=prob[i]
            cprob[i]=acum

            
        rest = B-A

        #R1
        nkeys = rest+1
        r10 = cprob[A-1]*nkeys
        nkeys = rest+1+B+1
        r11 = (1-cprob[A-1])*nkeys
        r1 = r10 + r11
 #       print r10, r11, r1 
        #R2
        r2min = 999999999999
        for i in range(A):
            k = A-i-1
            
            if k == 0:
                p = 1
            else:
                p = cprob[k-1]
            nkeys = 2*(i+1)+rest+1
            #print A-i, nkeys,
            r21 = p*nkeys
            nkeys = 2*(i+1)+rest+1+B+1
            r22 = (1-p)*nkeys
#            print i, nkeys, (1-p)
            r2 = r21+r22
            if r2 < r2min:
                r2min = r2
            #print i, r21, r22, r2
        r2 = r2min
        #R3

        r3 = B +2
#        print r1, r2, r3
        print "Case #%d: %0.6f"%(nc+1,  min([r1,r2,r3]))

            
