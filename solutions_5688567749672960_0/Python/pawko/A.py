# python 3
import string
import itertools
import sys

MAX_N = 1000000
def init_xtab():
    xtab = [MAX_N] * (MAX_N+1)
    xtab[1] = 1
    for i in range(1, MAX_N+1):
        if i<MAX_N:
            xtab[i+1] = min(xtab[i+1], xtab[i]+1)
        flipped = int(str(i)[::-1])
        if flipped > i:
            xtab[flipped] = min(xtab[flipped], xtab[i]+1)
    return xtab

XTAB = init_xtab()


def process_case(N):
    result = XTAB[N]
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        N = int(next(lines))
        result = process_case(N)
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
    with open(infile, 'r') as f_in, open(outfile, 'w') as f_out:
        f_out.writelines(result_gen(input_gen(f_in)))

##start('A-test')
start('A-small-attempt0')
##start('A-large')
