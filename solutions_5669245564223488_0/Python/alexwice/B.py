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
                print i+1, res
                write_case(fo, i+1, res)
def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

#######################################################

def read_case(f):
    N = read_int(f)
    A = read_words(f)
    return N,compress(A)

#######################################################

def fusion(x):
    if x == []: return []
    #If some have to sit together, stick them now
    a,b = x[0],x[1:]
    if b == []: return x
    ct = 0
    ma = ''
    for i in b:
        if a[-1] == i[0]:
            ct += 1
            ma = i
    if ct == 1 and a[0] != ma[-1]:
        b.remove(ma)
        return [a+ma]+fusion(b)
    return [a]+fusion(b)

def compr(x):
    ans = ''
    cur = ''
    for i in x:
        if cur == i: pass
        else:
            ans = ans + i
            cur = i
    return ans

def compress(x):
    ans = []
    for i in x:
        ans.append(compr(i))
    return fusion(ans)


def valid(x):
    #All ocurrences of the same character are adjacent to each other
    y = "".join(x)
    seen = set([])
    cur = ''
    for i in y:
        if i != cur:
            z = i in seen
            if z:
                return False
            if cur=='' or (not z):
                seen.add(i)
                cur = i
    return True
def solver(case):
    N,A = case
    nn = len(A)
    if N ==1: return 1
    z = "".join(A)
    lets = set(z)
    for i in lets:
        if z.count(i) == 1:
            for j in xrange(nn):
                if A[j] and (i in A[j]):
                    mm = A[j]
                    mm = mm.replace(i,'')
                    A[j] = mm
    print A
    ct = 0
    for i in itertools.permutations(A):
        if valid(i):
            ct += 1
    return ct


    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
