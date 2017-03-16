from gcjbase import *
from collections import Counter
from itertools import permutations, combinations_with_replacement
import decimal

import math

def read_input(filename):
    data = []
    with open(filename, "r") as f:
        cases = read_ints(f)[0]
        # =============================================
        for _ in xrange(cases):
            N, X, Y = read_ints(f)
            data.append({"N": N,
                         "X": X,
                         "Y": Y})
        # =============================================
    return data

def make_output(fname, output):
    CASE_PRFX = "Case #%s: "
    fname = fname + time.strftime("%H%M%S") + ".out"
    with open(fname, "w") as f:
        # =============================================
        restext = []
        print "Output content ==============="
        for i, v in enumerate(output):
            line = CASE_PRFX % (i+1,) + str(v) + "\n"
            print line[:-1]
            restext.append(line)
        print "=" * 30
        f.writelines(restext)
        # =============================================

# ----------------------------------------------------------------------

@memoizeit
def fact(m):
    return math.factorial(m)

@timeit
@memoizeit
def coin_toss_min(totM, mintgt):
    """ probability of at least `mintgt` heads in `totM` tosses """
    inverse = mintgt < (totM / 2)
    denom = decimal.Decimal(fact(totM))
    total_no = decimal.Decimal(2 ** totM)
    calc = decimal.Decimal(0.0)
    if inverse:
        i = 0
        while i < mintgt:
            calc += decimal.Decimal(1.0) / (decimal.Decimal(fact(i)) * decimal.Decimal(fact(totM-i))) 
            i += 1
        return 1 - (denom * calc / total_no)
    i = mintgt
    while i <= totM:
        calc +=  decimal.Decimal(1.0) / (decimal.Decimal(fact(i)) * decimal.Decimal(fact(totM-i))) 
        i += 1
    return denom * calc / total_no
    
    
@timeit
def h(x, y):
    return 0.5 * (abs(x) + y)

@timeit
def stag(x, y):
    return y + 1

@timeit
def s(h):
    return 2*h +1

@timeit
def T(h):
    return 2 * h * h + 3 * h + 1

@timeit
def NLow(x, y):
    return T(h(x, y)-1) + stag(x, y) -1

@timeit
def NHigh(x, y):
    return T(h(x, y)-1) + stag(x, y) + s(h(x, y)) -1 
    
@timeit
def solveit(case):
    print case
    N = case["N"]
    X = case["X"]
    Y = case["Y"]
    
    if N <= NLow(X, Y):
        return 0
    if N >= NHigh(X, Y):
        return 1
    
    if X == 0:
        if N == T(h(X, Y)):
            return 1
        return 0
    
    
    M = N - T(h(X, Y)-1)
    
    
    
    p = coin_toss_min(M, stag(X, Y))
    
    return p

@timeit
def main(fname):
    data = read_input(fname)
    output = []
    for i, case in enumerate(data):
        statreset() # reset cache stats
        # =============================================
        res = solveit(case)
        output.append(res)
        # =============================================
    make_output(fname, output)


if __name__ == '__main__':
    main("B-large.in")
    #main("test.in")
#    main("A-small-attempt2.in")
#    main("A-large.in")