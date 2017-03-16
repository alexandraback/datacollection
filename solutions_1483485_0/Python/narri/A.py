import multiprocessing
import sys
import optparse
import os
import string
S = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
Y = """our language is impossible to understand
there are twenty six factorial possibilities
 so it is okay if you want to just give up"""

S = ''.join(i for i in S if i.isalpha())
Y = ''.join(i for i in Y if i.isalpha())
Z = dict(zip(S,Y))
Z['z'] = 'q'
Z['q'] = 'z'

def solve_case(line):
    return ''.join(Z.get(i,i) for i in line)
    
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, answer)

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for i in xrange(N):
        yield (cin().strip(),)

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
