#!/usr/bin/env python
#By Jai Dhyani    
 
import math, sys, os
 
def getints(f):
    return [int(x) for x in f.readline().split()]

def solve( data ):
    N=float(data[0])
    scores=data[1:]
    original_scores=scores[:]
    X=float(sum(scores))
    aud_remaining=1.0
    while True:
        lowest=min(scores)
        next_lowest=max(scores)
        for s in scores:
            if s>lowest and s<next_lowest:
                next_lowest=s
        num_lowest=scores.count(lowest)
        aud_needed=num_lowest*(next_lowest-lowest)/X
        print aud_needed
        if aud_needed<aud_remaining and num_lowest<N:
            aud_remaining-=aud_needed
            for i,s in enumerate(scores):
                if s==lowest:
                    scores[i]=next_lowest
        else:
            bonus=X*aud_remaining/num_lowest
            for i,s in enumerate(scores):
                if s==lowest:
                    scores[i]+=bonus
            break
    E=min(scores)
    print E
    Ys=[max(100*(E-j_i)/X,0.0) for j_i in original_scores]
    return Ys

if __name__ == '__main__':
    filenames = [f for f in os.listdir('.') if f[-2:]=='in']
    for filename in filenames:
        outname=filename+'.out'
        f=open(filename)
        out=open(outname,'w')
        try:
            numtrials = getints(f)[0]
        except IndexError as ie:
            exit(0)
        for i in xrange(numtrials):
            answer_num = solve(getints(f))
            answer_str = "Case #%d: %s"%(i+1,' '.join([str(x) for x in answer_num]))
            print(answer_str)
            out.write(answer_str+'\n')
