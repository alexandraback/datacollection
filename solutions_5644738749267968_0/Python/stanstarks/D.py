import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

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
                res = solver(case)
                write_case(fo, i, res)

################################################################################

def read_case(f):
    N = read_int(f)
    A = read_floats(f)
    B = read_floats(f)
    return N, A, B

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')


################################################################################

def solve_small(case):
    N, A, B = case
    A.sort(reverse=True)
    B.sort(reverse=True)
    a1 = A[:]
    b1 = B[:]
    l1 = 0
    while(len(b1)>0):
        if (b1[-1]>a1[-1]):
            l1 = l1 + 1
            a1.pop()
        b1.pop()
    w2 = 0
    while(len(A)>0):
        if (A[0] > B[0]):
            w2 = w2 + 1
            A.pop(0)
        else:
            A.pop()
        B.pop(0)
    return "%d %d" % (w2, N-l1)
    
solve_large = solve_small

solve(solve_large, 'D-small-attempt0')

