def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1),
        print solve_case(*map(float, f.readline().strip().split()))

def solve_case(C, F, X):
    t = 0.0
    prod = 2.0
    while True:
        no_buy = X / prod
        buy = C / prod + X / (prod + F)
        if no_buy < buy:
            t += no_buy
            break
        else:
            t += C / prod
            prod += F
    return t

import sys
parse(sys.stdin)
