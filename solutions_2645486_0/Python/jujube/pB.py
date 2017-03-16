#!/usr/bin/env pypy

import sys

file_name = 'Sample.in'
# file_name = 'B-small-attempt0.in'
# file_name = 'A-small-attempt0.in'
# file_name = 'A-large.in'
#file_name = 'B-large.in'
file_name = 'B-small-attempt0.in'

# open input file
try:
    with open(file_name, 'r') as f:
        num_cases = int(f.readline())
        in_lines = []
        for i in f.readlines():
            i = i.strip('\n')
            if i != '':
                in_lines.append(i)
        in_lines = tuple(in_lines)
except EnvironmentError:
    print "Can't open input file!"
    sys.exit(-1)

# process the input file
assert len(in_lines) % 2 == 0
E = []
R = []
vals = []
for i in range(len(in_lines) / 2):
    ee, rr, nn = map(int, in_lines[2 * i].split())
    E.append(ee)
    R.append(rr)
    vals.append(tuple(map(int, in_lines[2 * i + 1].split())))
    assert nn == len(vals[-1])
E = tuple(E)
R = tuple(R)
vals = tuple(vals)


def fun(eng, max_eng, regain, next_vals):
    if len(next_vals) == 1:
        # print eng, max_eng, regain, next_vals, '=>', eng * next_vals[0]
        return eng * next_vals[0]

    min_spend = eng + regain - max_eng
    if min_spend < 0:
        min_spend = 0

    max_outcome = -1
    # best_spend = None
    for spend in range(min_spend, eng + 1):
        outcome = spend * next_vals[0] \
            + fun(eng - spend + regain, max_eng, regain, next_vals[1:])
        if outcome > max_outcome:
            max_outcome = outcome
            # best_spend = spend

    # print min_spend, '<', eng, 'best', best_spend
    # print eng, max_eng, regain, next_vals, '=>', max_outcome
    return max_outcome


def compute(idx):
    # print 'input:', E[idx], E[idx], R[idx], vals[idx]
    return fun(E[idx], E[idx], R[idx], vals[idx])


out_lines = []
for i in range(num_cases):
    lin = 'Case #' + str(i + 1) + ': '
    lin += str(compute(i))
    print lin
    out_lines.append(lin)

if 'Sample.in' == file_name:
    try:
        with open('Sample.out', 'r') as f:
            sample_out_lines = [i.strip('\n') for i in f.readlines()]
    except:
        print "Can't open sample output file"
        sys.exit(-2)
    # need to test smaple output later


# test sample output
if 'Sample.in' == file_name:
    assert str(out_lines) == str(sample_out_lines)
