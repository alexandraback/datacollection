# Encoding: utf-8
'''
Created on 13.04.2013

@author: Los

@version: 0.0.1
'''
import sys
import time
import math

#MAX=1000
MAX=100000000000000
#MAX=10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

MAKE_DB=0
USE_DB=0

def isFair(x):
    s=str(x)
    if s==s[::-1] :
        return True
    else :
        return False

def main(argv=None):
    if argv==None : argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')

    fns=list()
    if USE_DB==0 :
        ctime=time.time()
        for x in range(1, MAX+1):
            if isFair(x):
                sq=x*x
                if sq>MAX :
                    break
                if isFair(sq) :
                    fns.append(sq)
            if time.time()-ctime > 60 :
                print (sq, int(math.log10(sq)))
                ctime=time.time()
        #print(fns)
    else :
        f=open('pc_db.db','r')
        EOF=False
        while not EOF :
            l=f.readline()
            if l=='' :
                EOF=True
                break
            l=l.strip()
            if l != '' :
                fns.append(int(l))
        f.close()
    
    if MAKE_DB==1 :
        f=open('pc_db.db','w')
        for x in fns:
            print(x, file=f)
        f.close()
    
    
    T=int(input())
    for i in range (1,T+1):
        l=input().strip().split()
        A=int(l[0])
        B=int(l[1])
        count=0
        for x in fns :
            if A<=x<=B :
                count+=1
        print('Case #{}: {}'.format(i,count))
    
    
if __name__ == '__main__':
    main()
