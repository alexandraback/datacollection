# python 3
import string
import itertools
import sys
from pprint import pprint

def letter_counts(s):
    cnt = [(k, sum(1 for i in g)) for k,g in itertools.groupby(s)]
    return cnt

def process_case(A, B, K):
    result = 0
    for a in range(A):
        for b in range(B):
            x = a & b
            if x < K:
                result += 1
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        A,B,K = line_of_numbers(next(lines))
        result = process_case(A, B, K)
        yield 'Case #{0}: {1}\n'.format(ci, result)
    
def line_of_numbers(s):
    return [int(sub) for sub in s.split()]

def input_gen(f_in):
    for line in f_in:
        if line.endswith('\n'):
            line = line[:-1]
        yield line

def start(basename):
    infile = basename + '.in'
    outfile = basename + '.out'
    f_in = open(infile, 'r')
    f_out = open(outfile, 'w')
    f_out.writelines(result_gen(input_gen(f_in)))
    f_in.close()
    f_out.close()

##start('B-test')
start('B-small-attempt0')
##start('B-large')
