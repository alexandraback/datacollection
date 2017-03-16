#!/usr/bin/env python
from numpy import zeros, int16

def answerstring(a,b,N):
    result="Too Bad"
    plays=0
    stars=0
    while stars < 2*N:
        bindex=b.argmin()
        if b[bindex] <= stars:
            a[bindex]=9999
            b[bindex]=9999
            plays = plays+1
            stars = stars+2
        else:
            aindex=a.argmin()
            if a[aindex] <= stars:
                a[aindex]=8888
                plays = plays+1
                stars = stars+1
            else:
                break
        #print 'plays,stars:',plays,stars
        #print 'a:',a
        #print 'b:',b
    if stars >= 2*N:
        result=plays
    return str(result)

def solve(infilename):
    infile=open(infilename,'r')
    T=int(infile.readline())
    #print 'T:',T
    for index in range(T):
        N=int(infile.readline())
        #print 'N:',N
        a=zeros(N,int16)
        b=zeros(N,int16)
        for lindex in range(N):
            ab=[int(i) for i in infile.readline().split()]
            a[lindex]=ab[0]
            b[lindex]=ab[1]
        #print 'a',a
        #print 'b',b
        answer=answerstring(a,b,N)
        print 'Case #%(index)d: %(answer)s' % {"index":index+1,"answer":answer}
    infile.close()
    return

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        solve(sys.argv[1])
    else:
        solve('input_example.in')
