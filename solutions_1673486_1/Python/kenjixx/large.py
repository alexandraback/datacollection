#!/usr/bin/env python
import itertools, collections
import sys
import math
import fractions
import string

def input_read(filename):
    data = None
    with open(filename) as f:
        for x in f:
            yield [a.strip() for a  in x.split()]

def output_file(filename, ans):
    with open(filename, 'w') as f:
        for n, a in enumerate(ans,1):
            f.write('Case #%d: %0.6f\n' % (n, a))
    return

def gen_testcase(ifilename):
    itera = input_read(ifilename)
    [T] = next(itera)
    for x in xrange(int(T)):
        l = next(itera)
        a = int(l[0])
        b = int(l[1])
        p = [(float(z) * 10**6) for z in next(itera)]
        assert(a == len(p))
        print a, b, p
        yield a, b, p

def correct_m(p, m):
    psb = 1
    for x in xrange(m):
        psb = psb * p[x]
    return psb

def prepare_m(p):
    psb = 1
    pms = []
    for n, x in enumerate(p,1):
        psb = psb * x / ( 10 ** 6 ) 
        pms.append(psb)
    return pms

def option1(a, b, pms):
    ans = (pms[a-1] ) * (-b -1) + ( 2*b -a + 2 )
    return ans

def option2(a, b, pms, x):
    ans = (pms[a-x-1]) * (-b -1) + ( 2*x + 2*b - a + 2)
    return ans

def option3(b):
    return b + 2

def solve_one(a, b, p):
    cand = []
    pms = prepare_m(p)
    for x in xrange(1, a/2+1):
        cand.append(option2(a, b, pms, x))
    cand.append(option1(a, b, pms))
    cand.append(option3(b))
    print cand
    return min(cand)

def solve_all(inputfile):
    for a, b, p in gen_testcase(inputfile):
         yield solve_one(a, b, p)

def main(ifile, ofile):
    output_file(ofile, solve_all(ifile))
    return

if __name__ == '__main__':
    from optparse import OptionParser
    parser = OptionParser()
    #parser.add_option('-i', type='string', dest='ifile', help='input filename', default='input.txt')
    parser.add_option('-o', type='string', dest='ofile', help='output filename', default='output.txt')
    
    (options, args) = parser.parse_args()
    if len(args) != 1:
        parser.print_help()
        sys.exit()

    try:
        main(args[0], options.ofile)
    except IOError as data:
        print data

