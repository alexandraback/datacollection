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
    A = []
    for i in xrange(4):
        A.append(read_letters(f))
    x = read_word(f)
    return A

#######################################################


def solver(case):
    A = case
    #print A, "!!!"
    lines = [[A[i][0],A[i][1],A[i][2],A[i][3]] for i in range(4)]
    lines = lines + [[A[0][i],A[1][i],A[2][i],A[3][i]] for i in range(4)]
    lines = lines + [[A[0][0],A[1][1],A[2][2],A[3][3]],[A[0][3],A[1][2],A[2][1],A[3][0]]]
    #print '!!!!'
    #print lines
    ans = ''
    for i in lines:
        if (i.count('X') == 3 and i.count('T') == 1) or (i.count('X') == 4):
            return 'X won'
        if (i.count('O') == 3 and i.count('T') == 1) or (i.count('O') == 4):
            return 'O won'
    for i in lines:
        if '.' in i:
            return 'Game has not completed'
    return 'Draw'

    
#False for large
#solve(solver,True)
solve(solver,False)

print 'Done'
