#!/usr/bin/env python
from numpy import array,cumprod,insert,append,arange,min,sum

def solve(infilename):
    infile=open(infilename,'r')
    line=infile.readline()
    T=int(line)
    for index in range(T):
        A,B=[int(i) for i in infile.readline().split()]
        #print
        #print 'A,B:',A,B
        probs=(array([float(i) for i in infile.readline().split()]))
        #print 'probs:',probs

        #print 'assumed_correct:',arange(A+2)-1
        keys=insert(1+(B-A)+2*(A-arange(A+1)),0,1+B+1)
        #print 'keys:',keys
        altkeys=keys+B+1
        altkeys[0]=B+2
        altkeys[1]=keys[1]
        #print 'altkeys:',altkeys

        temp=cumprod(probs)
        #print temp
        for i in range(len(temp)-1):
            temp[i]=temp[i]*(1-probs[i+1])
        #print temp
        probNandNotNplus1=insert(temp,0,1-probs[0])
        #print 'probNandNotNplus1:',probNandNotNplus1
        cumprob=1.0*keys
        cumprob[0]=1
        for i in range(len(cumprob)-1):
            cumprob[i+1]=sum(probNandNotNplus1[i:])
        #print 'cumprob:',cumprob
        #print array([1,1,.6,.36])
        expect=cumprob*keys+(1.-cumprob)*altkeys
        #print 'expect:',expect
        answer=min(expect)
        print 'Case #%(index)d: %(answer).6f' % {"index":index+1,"answer":answer}
    infile.close()
    return

if __name__ == "__main__":
    import sys
    if len(sys.argv) > 1:
        solve(sys.argv[1])
    else:
        solve('input_example.in')
