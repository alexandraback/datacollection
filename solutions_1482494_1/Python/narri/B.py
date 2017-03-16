import multiprocessing
import sys
import optparse
import os
import collections
def memoized(f):
    se = dict()
    def ret(*args):
        if args in se:
            return se[args]
        x = f(*args)
        se[args] = x
        return x
    return ret
        
gooey = 0
def solve_case(reqs):
    N = len(reqs)
    twos = list()
    ones = list()
    for i, tup in enumerate(reqs):
        twos.append((tup[1],i))
        ones.append((tup[0],-1*tup[1], i))
    twos.sort()
    ones.sort(key=lambda x: (x[0], x[1], x[2]))
    have = 0
    at2 = 0
    at1 = 0
    uhoh = set()
    doneit = set()
    out = 0
    while True:
        while at2 < len(twos) and twos[at2][0] <= have:
            out += 1
            if twos[at2][1] in uhoh:
                have += 1
            else:
                have += 2
            doneit.add(twos[at2][1])
            at2 += 1
        #take some ones
        gg = False
        while at1 < len(ones) and ones[at1][0] <= have:
            _, _, idd = ones[at1]
            if idd not in doneit:
                uhoh.add(idd)
                have += 1
                out += 1
                gg = True
                at1 += 1
                break
            at1 += 1
        if not gg:
            break
                    
            
        
    if have != 2*N:
        return "Too Bad"
    return out
                
                
    
    
                     
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for t in xrange(N):
        A = int(cin())
        Z = [[int(x) for x in cin().strip().split()] for q in xrange(A) ]
        yield (Z,)
    

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
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            ans = solve_case(*args)
            print format_answer(cn+1, ans)
            cn += 1            

if __name__ == '__main__':
    main()
