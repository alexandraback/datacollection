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
            yield [int(a.strip()) for a  in x.split()]

def output_file(filename, ans):
    with open(filename, 'w') as f:
        for n, a in enumerate(ans,1):
            f.write('Case #%d: %s\n' % (n, a))
    return

def gen_testcase(ifilename):
    itera = input_read(ifilename)
    [T] = next(itera)
    for x in xrange(T):
        a = next(itera)
        n = a[0]
        s = a[1]
        p = a[2]
        ts = a[3:] 
        assert(n == len(ts))
        print n, s, p, ts
        yield n, s, p, ts

def solve_one(n, s, p, ts):
    ans = 0
    cs = int(s)
    for v in ts:
        print v
        pm1 = p - 1 if p > 0 else 0
        pm2 = p - 2 if p > 1 else pm1
        #check with no supprising score
        if v >= (p + pm1 + pm1) :
            ans += 1
        #if cannot, check with supprising score
        elif v >= (p + pm2 + pm2) and cs > 0:
            cs -= 1
            ans += 1
        else:
            #cannot
            pass
    return ans

def solve_all(inputfile):
    for n, s, p, ts in gen_testcase(inputfile):
         yield solve_one(n, s, p, ts)

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

