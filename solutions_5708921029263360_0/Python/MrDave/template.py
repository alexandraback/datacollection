
import csv
import itertools
import copy
import time
import numpy as np
import collections
import operator


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        test_lst.append([int(e) for e in csv_r.next()])
    f.close() 
    return test_lst 


def gen_iterator(j, p, s, J, P, S):
    if s<S-1:
        s+=1
        return j, p, s
    if p<P-1:
        p+=1
        return j, p, 0
    if j<J-1:
        j+=1
        return j, 0, 0
    return None, None, None

def iterator1(j, p, s, J, P, S):
    return gen_iterator(j, p, s, J, P, S)

def iterator2(j, p, s, J, P, S):
    p,j,s=gen_iterator(p, j, s, P, J, S)
    return j, p, s

def iterator3(j, p, s, J, P, S):
    p,s,j=gen_iterator(p, s, j, P, S, J)
    return j, p, s

def iterator4(j, p, s, J, P, S):
    j,s,p =gen_iterator(j, s, p, J, S, P)
    return j, p, s
    
def iterator5(j, p, s, J, P, S):
    s,j,p =gen_iterator(s, j, p, S, J, P)
    return j, p, s

def iterator6(j, p, s, J, P, S):
    s,p,j =gen_iterator(s, p, j, S, P, J)
    return j, p, s


def solve_simple(test_case, iterator):
    J, P, S, K = test_case
    d={}
    j,p,s=0,0,0
    res=[]
    while True:
        if (j, p, s) not in d and d.get(('JP',j,p),0)<K\
                              and d.get(('JS',j,s),0)<K\
                              and d.get(('PS',p,s),0)<K:
           res.append((j, p, s))
           d[(j, p, s)]=None
           if ('JP',j,p) not in d: 
               d[('JP',j,p)]=0
           if ('JS',j,s) not in d: 
               d[('JS',j,s)]=0
           if ('PS',p,s) not in d: 
               d[('PS',p,s)]=0
           d[('JP',j,p)] +=1
           d[('JS',j,s)] +=1
           d[('PS',p,s)] +=1
        #else:
        #   print 'discarding', j, p, s
        #   print d
        #   raise
        j, p, s=iterator(j, p, s, J, P, S)
        if j is None:
            break
    return res
        

def solve_test(test_case):
    best=None
    for it in iterator1, iterator2, iterator3, iterator4, iterator5, iterator6:
        res=solve_simple(test_case, it)
        if best is None or len(best) < len(res):
            best=res
    return best


def main(filename):
    test_lst = read_file(filename)
    for i_test, test_case in enumerate(test_lst):
        res = solve_test(test_case)
        print "Case #%i: %s" % (1+i_test, len(res))
        for row in res:
            print " ".join([str(e+1) for e in row])


if __name__ == '__main__':
    #main('./simple.in')
    main('./C-small-attempt1.in')
    #main('./A-large.in')


