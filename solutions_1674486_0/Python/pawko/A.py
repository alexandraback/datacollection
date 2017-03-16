# python 3
import string
import itertools
import sys

def diamond_ref(refs, i, refcount):
    refcount[i] += 1
    if refcount[i] >= 2:
        return True
    for j in refs[i]:
        if diamond_ref(refs, j, refcount):
            return True
    return False

def process_case(refs):
    n = len(refs)
    for i in range(n):
        refcount = [0] * n
        if diamond_ref(refs, i, refcount):
            return True
    return False

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        n = int(next(lines))
        refs = [decrement_all(line_of_numbers(next(lines))[1:])
                for i in range(n)]
        print(refs)
        result = process_case(refs)
        result_str = 'Yes' if result else 'No'
        yield 'Case #{0}: {1}\n'.format(ci, result_str)
    
def decrement_all(nums):
    return [x-1 for x in nums]

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

##start('A-test')
start('A-small-attempt0')
##start('A-large')
