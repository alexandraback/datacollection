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
def solve_case(me, him):
    lookup_d = dict((y,x) for (x,y) in enumerate(sorted(me + him)))
    me = [lookup_d[i] for i in sorted(me)]
    him = [lookup_d[i] for i in sorted(him)]
    N = len(me)
    def deceit():
        out = 0
        hq = him[:]
        for i in me:
            if i > hq[0]:
                out += 1
                hq = hq[1:]
            else:
                hq = hq[:-1]
        return out

    def war():
        hq = him[:]
        out = 0
        for i in me:
            if i > hq[-1]:
                out += 1
                hq = hq[1:]
            else:
                min_idx = min(z for z in xrange(len(hq)) if hq[z] > i)
                hq = hq[:min_idx] + hq[min_idx+1:]
        return out
    return deceit(), war()
                            
def format_answer(cn, answer):
    return "Case #%d: %d %d" % (cn, answer[0], answer[1])

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        q = int(cin())
        X = [float(x) for x in cin().strip().split()]
        Y = [float(x) for x in cin().strip().split()]
        yield (X,Y)
        
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

