# python 3
import string
import itertools
import sys
import fractions

def find_pos(xmap):
    for r in range(len(xmap)):
        for c in range(len(xmap[r])):
            if xmap[r][c] == 'X':
                return r,c

def cycles(outer_size, pos, D):
    inner_size = outer_size - 2
    round_trip = 2 * inner_size
    d1 = 2 * pos - 1
    d2 = round_trip - d1
    result = [0]
    for d in range (d1, D+1, round_trip):
        result.append(-d)
    for d in range (d2, D+1, round_trip):
        result.append(d)
    for d in range (round_trip, D+1, round_trip):
        result.append(-d)
        result.append(d)
    return result
    
def unique_direction(dr, dc):
    if dc == 0:
        return (dr/abs(dr), 0)
    if dr == 0:
        return (0, dc/abs(dc))
    div = abs(fractions.gcd(dr, dc))
    return (dr/div, dc/div)

def process_case_simple(H,W,D,xmap):
    xr,xc = find_pos(xmap)
    r_cyc = cycles(H, xr, D)
    c_cyc = cycles(W, xc, D)
    directions = set()
    for rd in r_cyc:
        for cd in c_cyc:
            if rd != 0 or cd != 0:
                if rd*rd + cd*cd <= D*D:
                    directions.add(unique_direction(rd, cd))
    return len(directions)

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        H,W,D = line_of_numbers(next(lines))
        xmap = [next(lines) for i in range(H)]
        result = process_case_simple(H,W,D,xmap)
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

##start('D-test')
start('D-small-attempt0')
##start('D-large')
