import multiprocessing
import sys
import optparse
import os

def solve_case(A, B):
    out = 0
    for n in xrange(A, B+1):
        s = str(n)
        z = set()
        for i in xrange(1,len(s)+1):
            m = int(s[i:] + s[:i])
            if n < m <= B and len(s) == len(str(m)):
                z.add(m)
        out += len(z)
                
    return out

def format_answer(cn, answer):
    return "Case #%d: %d" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for i in xrange(N):
        line = cin().strip().split()
        yield (int(line[0]),int(line[1]))

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
