#!/usr/bin/env pypy

import sys

# file_name = 'Sample.in'
# file_name = 'B-small-attempt0.in'
file_name = 'A-small-attempt0.in'
#file_name = 'B-large.in'

# open input file
try:
    with open(file_name, 'r') as f:
        num_cases = int(f.readline())
        in_lines = [i.strip('\n') for i in f.readlines()]
except EnvironmentError:
    print "Can't open input file!"
    sys.exit(-1)

# process the input file
test_cases = []
for lin in in_lines:
    if lin != '':
        tup = lin.split(' ')
        r = int(tup[0])
        t = int(tup[1])
        test_cases.append(tuple([r, t]))
test_cases = tuple(test_cases)
# from pprint import pprint
# pprint(test_cases)


def result(r, t):
    n = 0
    while t >= 2 * r + 1:
        nex = 2 * r + 1
        t -= nex
        r += 2
        n += 1
    return n


out_lines = []
for i in range(num_cases):
    lin = 'Case #' + str(i + 1) + ': '
    lin += str(result(test_cases[i][0], test_cases[i][1]))
    out_lines.append(lin)
    print lin
# from pprint import pprint
# pprint(out_lines)


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
