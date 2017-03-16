import multiprocessing
import sys
import optparse
import os

def memoized(f):
    se = dict()
    def ret(*args):
        if args in se:
            return se[args]
        x = f(*args)
        se[args] = x
        return x
    return ret

import collections
import random
def solve_case(C, F, X):
    best = X * 0.5
    num_farms = 0
    curr_base = 0.0
    while True:
        x = C / (2.0 + F * num_farms)
        curr_base += x
        num_farms += 1
        z = curr_base + (X / (2.0 + F * num_farms))
        if z > best:
            break
        best = z
    return best
                            
def format_answer(cn, answer):
    return "Case #%d: %.12lf" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        A, B, C = [float(x) for x in cin().strip().split()]
        yield (A, B, C)
        
def main():
    parser = optparse.OptionParser()
    parser.add_option('--nprocs', type='int', help='parallelize with n procs')
    parser.add_option('--skip', type='int', help='skip this many cases', default=0)
    options, args = parser.parse_args()

    np = options.nprocs
    
    skip = options.skip
    if np is not None:
        pool = multiprocessing.Pool(processes=np)
        procs = []
        cn = 0
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            procs.append((cn, pool.apply_async(solve_case, args=args)))
            cn += 1
        for i, proc in procs:
            ans = proc.get()
            print format_answer(i+1, ans)
    else:
        cn = 0
        #print "OMG"
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            ans = solve_case(*args)
            print format_answer(cn+1, ans)
            cn += 1            

if __name__ == '__main__':
    main()

