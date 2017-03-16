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

#######################################################

def read_case(f):
    N = read_int(f)
    A = read_floats(f)
    B = read_floats(f)
    return A,B,N
    #binary search

#######################################################

def digest(X,Y):
    ans = []
    X.sort()
    Y.sort()
    try:
        while True:
            if X[0] < Y[0]:
                X = X[1:]
                ans.append(0)
            else:
                Y = Y[1:]
                ans.append(1)
    except: #one is empty
        if X == []:
            for i in Y:
                ans.append(1)
        else:
            for i in X:
                ans.append(0)
    return ans

def warsolve(X):
    ct = 0
    sc = 0
    for i in X:
        if i == 1:
            if ct > 0:
                ct -= 1
                sc += 1
        if i == 0:
            ct += 1
    return sc

def solver(case):
    A,B,N = case
    D = digest(A,B)
    R = list(D)
    for i in xrange(len(R)):
        z = R[i]
        if z == 0: R[i] = 1
        elif z == 1: R[i] = 0
    return str(warsolve(R))+' '+str(N-warsolve(D))



    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
