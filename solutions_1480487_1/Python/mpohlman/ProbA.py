#!/usr/bin/env python

def solve(infilename):
    infile=open(infilename,'r')
    line=infile.readline()
    T=int(line)
    #print 'T:',T
    for index in range(T):
        linesplit=infile.readline().split()
        N=int(linesplit[0])
        s=[int(i) for i in linesplit[1:N+1]]
        #print
        #print 'N:',N
        #print 's:',s
        x=float(sum(s))
        #print 'x:',x
        safeflag=[int((2*x/N) <= i) for i in s]
        numsafe=sum(safeflag)
        #print 'safeflag:',safeflag
        safesum=0
        for i in range(N):
            safesum=safesum+(1-safeflag[i])*s[i]
        fraction=[((x+safesum)/(N-numsafe)-i)/x for i in s]
        for i in range(N):
            if (safeflag[i] >0):
                fraction[i]=0
        #print 'fraction:',fraction
        totalfrac=sum(fraction)
        #print 'totalfrac:',totalfrac
        answer=[100./totalfrac*i for i in fraction]
        answerstr=' '.join(["%f" % a for a in answer])
        print 'Case #%(index)d: %(answer)s' % {"index":index+1,"answer":answerstr}
    infile.close()
    return

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        solve(sys.argv[1])
    else:
        solve('input_example.in')
