# python 3
import string
import itertools
import sys

max_num = 2000000

def build_tab(max_idx):
    a = (max_idx+1)*[0]
    for num in range(1, max_idx+1):
        if a[num] > 0:
            continue
        cur=num
        for nxt in gen_rotations_in_range(num, 1, max_idx):
            a[cur] = nxt
            cur = nxt
        a[cur] = num
    return a

def gen_rotations_in_range(num, mini, maxi):
    for val in gen_rotations(num):
        if mini <= val <= maxi:
            yield val

def gen_rotations(num):
    digits = [ch for ch in str(num)]
    for i in range(1, len(digits)):
        if digits[i] != '0':
            result = 0
            for d in digits[i:]:
                result = 10*result + ord(d) - ord('0')
            for d in digits[:i]:
                result = 10*result + ord(d) - ord('0')
            if result == num:
                return
            yield result

def gen_rotations_from_tab(tab, num):
    val = tab[num]
    while val != num:
        yield val
        val = tab[val]

def process_case(tab, a, b):
    result = 0
    for n in range(a,b+1):
        for m in gen_rotations_from_tab(tab, n):
            if (n < m <= b):
                result += 1
    return result

def result_gen(lines):
    tab = build_tab(max_num)
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        a,b = line_of_numbers(next(lines))
        result = process_case(tab, a, b)
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

##start('C-test')
##start('C-small-attempt0')
start('C-large')
