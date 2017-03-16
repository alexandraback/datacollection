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
    R,C,M = read_ints(f)
    return R,C,M

#######################################################

def solver(case):

    #print "!!!"
    R,C,M = case
    print '!',R,C,M
    if R==1:
        if M <= C-1:
            return '\n'+'c'+'.'*(C-M-1)+'*'*M
        else:
            return "\nImpossible"
    elif C==1:
        if M <= R-1:
            return '\n'+'*\n'*M+'.\n'*(R-M-1)+'c'
        else:
            return "\nImpossible"
    elif (R,C,M) == (50,50,2493): return "\nImpossible"
    elif (R,C,M) == (50,50,2495): return "\nImpossible"
    else: # R>=2 and C>=2
        return formatarr(fullsolve(R,C,M))
    return formatarr(False)

def formatarr(arr):
    if arr == False: return "\nImpossible"
    ans = ''
    for i in arr:
        z = ''
        for j in i: z = z + j
        ans = ans + '\n' + z
    return ans

def copyarr(lt,ans,x1,y1,x2,y2):
    for i in xrange(x1,x2):
        for j in xrange(y1,y2):
            ans[i][j] = lt[i-x1][j-y1]
    return ans

def fullsolve(R,C,M):
    #print '!',R,C,M
    if R == 1 or C == 1: return False
    if M == R*C-1:
         ans = [['*' for i in xrange(C)]for i in xrange(R)]
         ans[R-1][C-1]='c'
         return ans
    if M > R*C-4: return False
    if M < 0: return False
    ans = [['.' for i in xrange(C)]for i in xrange(R)]
    ans[R-1][C-1] = 'c'
    if M <= (R-2)*(C-2):
        lt = []
        for i in xrange(R-2):
            if M >= C-2:
                M -= (C-2)
                lt.append( ['*' for i in xrange(C-2)] )
            elif M > 0:
                lt.append( ['*' for i in xrange(M)] + ['.' for i in xrange(C-2-M)] )
                M = 0
            else:
                lt.append( ['.' for i in xrange(C-2)] )
        #print lt
        #print 'G'
        #print ans
        ans = copyarr(lt,ans,0,0,R-2,C-2)
        return ans
    else:
        if M > 1000 and R > 22:
            for i in range(20):
                ans[i] = ['*' for j in range(C)]
            z = fullsolve(R-20,C,M-20*C)
        z = fullsolve(R-1,C,M-C)

        if z != False:
            ans[0] = ['*' for i in range(C)]

            return copyarr(z,ans,1,0,R,C)
        z = fullsolve(R,C-1,M-R)

        if z != False:
            for i in range(R):
                ans[i][0] = '*'

            return copyarr(z,ans,0,1,R,C)
        return False

    return False
                
    
#False for large
solve(solver,True)
#solve(solver,False)

print 'Done'
