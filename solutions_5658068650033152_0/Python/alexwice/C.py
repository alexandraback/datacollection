import sys
import itertools
import math
import collections
import functools

def read_word(f):
    return next(f).strip()
def read_int(f, b=10):
    return int(read_word(f), b)
def read_letters(f):
    return list(read_word(f))
def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]
def read_words(f, d=' '):
    return read_word(f).split(d)
def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]
def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]
def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res
def solve(solver,SMALL=True,PRACTICE=False):
    fn = sys.argv[0]
    fn = fn[ 1+fn.rfind('/'): fn.rfind('.') ]
    fn = fn+['-large','-small'][SMALL]+['','-practice'][PRACTICE]
    in_fn = fn + '.in'
    out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                if 1 not in case and 2 not in case:
                    print 'ans',i+1, case,res
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

#######################################################

def read_case(f):
    N,M,K = read_ints(f)
    return N,M,K

#######################################################

def solver(case):
    N,M,K=case
    #print case
    if K<=4: return K
    if N<=2 or M<=2: return K
    if N>=4 and M>=4 and K==10: return 7
    if N>M: N,M=M,N
    if N>=4 and M>=5 and K==14: return 9
    #2(a+b-2) -4 stones gets (a-2)(b-2) interior points
    maxi = N*M

    for i in xrange(3,N+1):
        for j in xrange(i,M+1):
            if i%2==0:
                w = i/2
                z = (j-2*w)
                pri = 2*i+2*z
                interior = (w*(w-1))*2 + (i-2)*z
            else:
                w = (i+1)/2
                z = (j-2*w)
                pri = 2*i+2*z
                interior = (w*(w-1))*2 - 2*(w-1) + (i-2)*z
            su = pri+interior
            goodies = w-1
            ct = 0
            while su < K:
                pri += 1
                su += goodies
                ct += 1
                if ct==4:
                    ct = 0
                    goodies -= 1
                if goodies == 1:
                    pri += K-su
                    su = K
            if pri < maxi:
                #print '!',i,j
                maxi = pri
                
            """
            pri = 2*(i+j-4)
            interior = (i-2)*(j-2)
            su = pri+interior
            if su < K:
                pri += K-su
            if pri < maxi:
                #print '!',i,j
                maxi = pri"""
    return maxi



    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
