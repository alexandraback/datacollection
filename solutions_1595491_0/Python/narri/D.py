import multiprocessing
import sys
import optparse
import os

def memoized(f):
    se = dict()
    def ret(*args):
        return se.setdefault(args, f(*args))
    return ret
        

def solve_case(S, p, scores):
    N = len(scores)
    @memoized
    def dp(at, sleft):
        if sleft < 0:
            return -10000
        if at == N:
            return 0
        ret = 0
        score = scores[at]
        a, b, c = False, False, False
        for x in xrange(11):
            for y in xrange(x, x+3):
                z = score - x - y
                if y <= z and z-x <= 2:
                    c = True
                    if z >= p:
                        if z - x == 2:
                            b = True
                        else:
                            a = True
                        
        if a:
            ret = max(ret, 1 + dp(at+1, sleft))
        if b:
            ret = max(ret, 1 + dp(at+1, sleft-1))
        ret = max(ret, dp(at+1, sleft))
        return ret
    return dp(0, S)
                   
def format_answer(cn, answer):
    return "Case #%d: %d" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for i in xrange(N):
        V = cin().strip().split()
        G,S,P = V[:3]
        yield (int(S), int(P), list(int(x) for x in V[3:]))

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
