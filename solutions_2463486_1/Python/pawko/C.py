# python 3

import math

def gen_half_digits_recur(digits, results, idx, points):
    if idx < 0:
        results.append(tuple(digits))
        return
    if idx+1 == len(digits):
        start=1
    else:
        start=0
    for d in range(start, 10):
        if 2*d*d <= points:
            digits[idx] = d
            gen_half_digits_recur(digits, results, idx-1, points - 2*d*d)

def gen_half_digits(max_digits):
    digits = [0]*max_digits
    results = []
    gen_half_digits_recur(digits, results, max_digits-1, 9)
    return results

def make_full_palin_num(half_digits):
    result = 0
    mul = 1
    for d in reversed(half_digits):
        result += d * mul
        mul *= 10
    for d in half_digits:
        result += d * mul
        mul *= 10
    return result

def gen_full_odd_palin_nums(half_digits):
    results = []
    points = 9 - 2 * sum(d*d for d in half_digits)
    for odd in range(10):
        if odd*odd > points:
            continue
        result = 0
        mul = 1
        for d in reversed(half_digits):
            result += d * mul
            mul *= 10
        result += odd * mul
        mul *= 10
        for d in half_digits:
            result += d * mul
            mul *= 10
        if result > 0:
            results.append(result)
    return results

def gen_palins(max_half_digits):
    results = []
    for hd_cnt in range(max_half_digits + 1):
        hd_results = gen_half_digits(hd_cnt)
        palins = [make_full_palin_num(hd) for hd in hd_results]
        results.extend(p for p in palins if p > 0)
        palins_tabs = [gen_full_odd_palin_nums(hd) for hd in hd_results]
        for pt in palins_tabs:
            results.extend(pt)
    return results


def process_case(lo, hi):
    cnt = 0
    for base in base_palindromes:
        if lo <= base*base <= hi:
            cnt += 1
    return cnt

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        lo,hi = line_of_numbers(next(lines))
        result = process_case(lo, hi)
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

# cover base palindromes up to 10**7, and squared palindromes up to 10**14
base_palindromes = gen_palins(4)

##start('C-test3')
##start('C-small-attempt0')
start('C-large-1')
