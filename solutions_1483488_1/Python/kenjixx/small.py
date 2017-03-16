#!/usr/bin/env python
import itertools, collections
import sys
import math
import fractions
import string

def take_n(iterable, n):
    itr = iter(iterable)
    xs = collections.deque()
    while True:
        for unused in xrange(n):
            xs.append(next(itr))
        yield tuple(xs)
        xs.clear()

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
        a, b = next(itera)
        print a, b
        assert ( len(str(a)) == len(str(b)) )
        yield a, b

def solve_one(a, b):
    if not a < b:
        return 0

    a_st = str(a)
    a_len = len(a_st)
    ans = 0 
    a_set = set() 
    for noi in xrange(a, b + 1):
        noi_st = str(noi)
        for t in xrange(1, a_len):
            num = int ( noi_st[t:a_len] + noi_st[0:t] )
            if a <= num and num <= b and noi < num:
                if (noi, num) not in a_set:
                    a_set.add((noi, num))
                    ans += 1
    return ans

def solve_all(inputfile):
    for a, b in gen_testcase(inputfile):
         yield solve_one(a, b)

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

