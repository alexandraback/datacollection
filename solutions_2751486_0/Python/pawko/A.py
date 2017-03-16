# python 3
import string
import itertools
import sys

vowels = 'aeiou'

def contains(word, start, end, n):
    cnt = 0
    for i in range(start, end):
        if word[i] in vowels:
            cnt = 0
        else:
            cnt += 1
            if cnt >= n:
                return True
    return False

def process_case(word, n):
    result = 0
    L = len(word)
    for j in range(1, L+1):
        for i in range(j):
            if contains(word, i, j, n):
                result += 1
    return result

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        (word, n) = next(lines).split(' ')
        n = int(n)
        result = process_case(word, n)
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

##start('A-test')
start('A-small-attempt0')
##start('A-large')
