# python 3
import string
import itertools
import sys

maxval = 10000

def process_case(data):
    n = len(data)
    tabsize = (1<<(2*n))
    tab = [maxval] * tabsize
    tab[0] = 0
    for state in range(tabsize):
        if tab[state] == maxval:
            continue
        all_stars = bin(state).count('1')
        for level in range(n):
            level_star_bits = (state >> (2*level)) & 3
            if level_star_bits < 1 and all_stars >= data[level][0]:
                state2 = state | (1<<(2*level))
                tab[state2] = min(tab[state2], tab[state] + 1)
            if level_star_bits < 3 and all_stars >= data[level][1]:
                state2 = state | (3<<(2*level))
                tab[state2] = min(tab[state2], tab[state] + 1)
    if tab[-1] == maxval:
        return "Too Bad"
    return tab[-1]

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        nlevels = int(next(lines))
        data = [line_of_numbers(next(lines))
                for i in range(nlevels)]
        result = process_case(data)
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
