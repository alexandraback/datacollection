# python 3
import string
import itertools
import sys
from pprint import pprint

def concat_zips(plan, zips):
    ret = ''
    for i in plan:
        ret += zips[i]
    return ret

def next_visit(i, visited, conns):
    while visited:
        if conns[visited[-1]][i]:
            visited.append(i)
            return True
        visited.pop()
    return False

def plan_valid(plan, conns):
    starting = plan[0]
    other = plan[1:]
    visited = [starting]
    for i in other:
        if not next_visit(i, visited, conns):
            return False
    return True

def process_case(N, zips, conns):
    print('processing...')
    p = list(range(N))
    p.sort(key=lambda i:zips[i])
    for plan in itertools.permutations(p):
        if plan_valid(plan, conns):
            return concat_zips(plan, zips)
    return None

def result_gen(lines):
    ncases = int(next(lines))
    for ci in range(1,ncases+1):
        N,M = line_of_numbers(next(lines))
        zips = [next(lines).strip() for i in range(N)]
        conns = [[0 for c in range(N)] for r in range(N)]
        for m in range(M):
            i,j = line_of_numbers(next(lines))
            i = i-1
            j = j-1
            conns[i][j] = 1
            conns[j][i] = 1
        result = process_case(N, zips, conns)
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
start('C-small-attempt0')
##start('C-large')
