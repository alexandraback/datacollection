
import math
import itertools
from collections import Counter
from fractions import gcd

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

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                print "case#%d"%(i+1),
                res = solver(case)
                write_case(fo, i+1, res)
                

################################################################################

def read_case(f):
    w = read_word(f)
    s = w.split("/")
    P= s[0]
    Q= s[1]
    return (P,Q)


def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def solve_small(case):
    (P,Q)=case
    P = int(P)
    Q = int(Q)
    xx = gcd(P,Q)
    P /=xx
    Q /=xx
    res = 0
    cnt = 0
    
    Qx = Q
    while Qx%2==0:
        Qx /=2
    if Qx!=1:
        print "impossible"
        return "impossible"
    
    while True:
#         print "P=%d, Q=%d"%(P,Q)
        
        if P>=Q:
             print cnt,
             print P,
             print Q,
             print ""
             return cnt
             break
        
#         if Q%2==1:
#             print "impossible",
#             print ""
#             return "impossible"
#             break
        

        else:
            Q /= 2
            cnt +=1
#             cnt +=1
#             if P%2 == 0:
#                 P = P/2
#             else:
#                 P = P//2+1
    
                
                 
    
    
    return res 


def solve_large(case):
    return solve_small(case)

DEBUG = 'f'



solve(solve_small, "2014_C_A")