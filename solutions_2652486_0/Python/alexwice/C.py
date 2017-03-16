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
    R,N,M,K = read_ints(f)
    rlts = []
    for i in xrange(R):
        rlts.append(read_ints(f))
    return R,N,M,K,rlts

#######################################################

def memo(f):
    class memo(dict):
        def __missing__(s,k):
            r = s[k] = f(k)
            return r
    return memo().__getitem__

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)

def prod(i):
    ans = 1
    for j in i:
        ans *= int(j)
    return ans

def sat(p,r):
    #p are a list of digits
    #r is a result set
    a = set([])

    for i in [1,p[0]]:
        for j in [1,p[1]]:
            for k in [1,p[2]]:
                a.add(i*j*k)
    #print a,p,"!",r
    return set(r).issubset( a)

        
def solver(case):
    R,N,M,K,rlts = case
    ans = '\n'
    #print case
    #forcing
    for rl in rlts:
        for i in itertools.combinations_with_replacement(range(2,M+1),N):
            #print i,rl
            if sat(i,rl):
                #print i
                ans = ans + ''.join(map(str,i)) + '\n'
                #print '!!!',ans
                break
    return ans
    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
