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
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')


    
######################################################

def read_case(f):
    E,R,N = read_ints(f)
    vlt = read_ints(f)
    return E,R,N,vlt

#######################################################

def memo(f):
    class memo(dict):
        def __missing__(s,k):
            r = s[k] = f(k)
            return r
    return memo().__getitem__

global ct
ct = 0


@memo
def gfn(tt):
    I,E,R,vlt,ct = tt
    #print tt
    vlt = list(vlt)
    if vlt == []: return 0
    #can spend up to I
    return max( [j*vlt[0] + gfn((min(I-j+R,E),E,R,tuple(vlt[1:]),ct)) for j in xrange(I+1) ] )
    
def solver(case):
    global ct
    ct += 1
    E,R,N,vlt = case
    #quick and dirty dp
    return gfn((E,E,R,tuple(vlt),ct))
    
    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
