#!/usr/bin/env python
#By Jai Dhyani

import math, sys, os
from operator import mul

def getints(f):
    chars_typed,chars_total=[float(x) for x in f.readline().split()]
    probs=[float(x) for x in f.readline().split()]
    return chars_typed,chars_total,probs


def prob_correct(probs,num_back):
    if num_back==len(probs):
        return 1.0
    else:
        return reduce(mul,probs[:-num_back])

def expected_back(probs,n,num_remaining,num_total):
    p_correct=prob_correct(probs,n)
    p_incorrect=1.0-p_correct
    return p_correct*(2.0*n+num_remaining+1)+p_incorrect*(2.0*n+num_remaining+num_total+2.0)

def expected( strat, chars_typed, chars_total, probs ):
    chars_remaining=chars_total-chars_typed
    if strat=='finish':
        p_correct=reduce(mul,probs)
        p_incorrect=1.0-p_correct
        cost_if_correct=chars_remaining+1.0
        cost_if_incorrect=chars_total+chars_remaining+2.0
        return p_correct*cost_if_correct + p_incorrect*cost_if_incorrect
    if strat=='backspace':
        print chars_typed
        return min( [ expected_back(probs,n,chars_remaining,chars_total) for n in xrange(1,int(chars_typed+1))])
    if strat=='giveup':
        return 2.0+chars_total

def solve( chars_typed,chars_total,probs):
    return min([ expected( strat, chars_typed, chars_total, probs ) for strat in 'finish','backspace','giveup'])

if __name__ == '__main__':
    filenames = [f for f in os.listdir('.') if f[-2:]=='in']
    for filename in filenames:
        outname=filename+'.out'
        f=open(filename)
        out=open(outname,'w')
        try:
            numtrials=int(f.readline())
        except IndexError as ie:
            print 'no input data in %s'%filename
            exit(0)
        for i in xrange(numtrials):
            answer_num = solve(*getints(f))
            answer_str = "Case #%d: %f"%(i+1,answer_num)
            print(answer_str)
            out.write(answer_str+'\n')
