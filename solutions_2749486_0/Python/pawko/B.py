# python 3
import string
import itertools
import sys

def process_case(x,y):
    result = ''
    if x>0:
        result += x * 'WE'
    if x<0:
        result += (-x) * 'EW'
    if y>0:
        result += y * 'SN'
    if y<0:
        result += (-y) * 'NS'
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        x,y = line_of_numbers(next(lines))
        result = process_case(x,y)
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
start('B-small-attempt1')
##start('B-large')
