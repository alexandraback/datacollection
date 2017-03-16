import sys
from sympy import *

N = int(sys.stdin.readline())

for i in range(1, N+1):
    r = sys.stdin.readline().split()
    num = int(r[0])
    syms = []
    res = 0
    a = Symbol('a')
    scores = []
    for j in range(1, num+1):
        s = 'x%d' % (j-1)
        syms.append(Symbol(s))
        scores.append(int(r[j]))
    x = sum(scores)
    
    eq = []
    for j in range(0, num):
        eq.append(Eq(scores[j]+x*syms[j], a))
    #eq.append(syms[1] > 0)
    eq.append(Eq(sum(syms), 1))

    y = solve(eq)
    print "Case #%d:" % i,
    
    # check if any are negative
    neg = False
    vals = []
    norm_sum = 0.0
    for j in range(1, num+1):
        v = y[syms[j-1]].evalf()
        if v < 0:
            neg = True
            v = 0.0
        else:
            norm_sum += v
        vals.append(v)

    #if neg:
        #for j in range(num):
            #vals[j] /= norm_sum
    
    for j in range(num):
        print "%.6f" % (100 * vals[j]),
    print
