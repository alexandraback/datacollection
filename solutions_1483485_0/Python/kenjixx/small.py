#!/usr/bin/env python
import itertools, collections
import sys
import math
import fractions
import string

#             abcdefghijklmnopqrstuvwxyz
googlerese = 'yhesocvxduiglbkrztnwjpfmaq' 

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
            yield x

def output_file(filename, ans):
    with open(filename, 'w') as f:
        for n, a in enumerate(ans,1):
            if a:
                f.write('Case #%d: %s\n' % (n, a) )
    return

def gen_testcase(ifilename):
    itera = input_read(ifilename)
    T = next(itera)
    for x in xrange(int(T)):
        a = next(itera)
        print a.strip()
        yield a.strip()

def solve_one(a):
    ans = ""
    for c in a:
        if c in string.ascii_lowercase:
            ans += googlerese[string.index(string.ascii_lowercase, c)]
        else:
            ans += c 
    return ans

def solve_all(inputfile):
    for a in gen_testcase(inputfile):
         yield solve_one(a)

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

