# python 3
import string
import itertools
import sys

def process_case(a, b, prob):
    result = 1 + b + 1  # just enter
    pp = 1.0
    keystrokes = a + b + 1  # delete all
    result = min(result, keystrokes + (1 + b) * (1.0 - pp))
    for p in prob:
        pp *= p
        keystrokes -= 2
        result = min(result, keystrokes + (1 + b) * (1.0 - pp))
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        a,b = line_of_numbers(next(lines))
        data = line_of_floats(next(lines))
        result = process_case(a, b, data)
        yield 'Case #{0}: {1}\n'.format(ci, result)
    
def line_of_numbers(s):
    return [int(sub) for sub in s.split()]

def line_of_floats(s):
    return [float(sub) for sub in s.split()]

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

##start('A-test')
start('A-small-attempt0')
##start('A-large')
