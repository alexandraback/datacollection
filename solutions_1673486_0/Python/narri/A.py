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
        
gooey = 0
def solve_case(A, B, probs):
    #give up
    LEFT = B-A
    out = 1 + B + 1
    #immediate
    z = []
    q = 1.0
    for i in probs:
        q *= i
        z.append(q)
    z = z[::-1] + [1.0]
    for i,p in enumerate(z):
        out = min(out, LEFT + 2*i + 1 + (1.0-p)*(B+1))
    return out
                     
def format_answer(cn, answer):
    return "Case #%d: %f" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for t in xrange(N):
        A, B = [int(i) for i in cin().strip().split()]
        probs = [float(i) for i in cin().strip().split()]
        yield A, B, probs
    

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
