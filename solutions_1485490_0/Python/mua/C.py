#!/usr/bin/env python
import fileinput
import sys
from collections import Counter
from itertools import tee, izip, imap, islice

lines_per_case = 3

def pairwise(iterable):
    "s -> (s0,s1), (s1,s2), (s2, s3), ..."
    a, b = tee(iterable)
    return izip(islice(a, 0, None, 2), islice(b, 1, None, 2))


def solve_case(case):
    boxes = pairwise(imap(int, case[1].strip().split()))
    toys = pairwise(imap(int, case[2].strip().split()))

    #print list(boxes), list(toys)
    
    return count_matches(list(boxes), list(toys))


def count_matches(boxes, toys):
    #print boxes, toys
    if len(boxes)  == 0 or len(toys) == 0:
        return 0

    nb = boxes.pop(0)
    nt = toys.pop(0)
    a = b = c = 0

    if nb[1] != nt[1]: # don't fit
        a = count_matches([nb] + boxes, list(toys)) # keep boxes
        b = count_matches(list(boxes), [nt] + toys)
    else:
        # which objects do we have more?
        #print 'match:', nb, nt
        if nb[0] >= nt[0]:
            c = nt[0]
            # either keep more boxes or throw away:
            a = count_matches([(nb[0] - nt[0], nb[1])] + boxes, list(toys))
        else:
            c = nb[0]
            b = count_matches(list(boxes), [(nt[0] - nb[0], nt[1])] + toys)
    
    return c + max(a, b)

def count_ke(boxes, toys):
    pass

def produce_output(index, solution):
    print 'Case #{0}: {1}'.format(index, solution)


def get_test_cases(lines, n_of_lines_per_case=1):
    x = 0
    while x < len(lines):
        y = x + n_of_lines_per_case
        yield lines[x:y]
        x = y

if __name__ == "__main__":
    lines = []
    if(len(sys.argv) > 1):
        fn = sys.argv[1]
        with open(fn) as f:
            lines = f.readlines()
    else:
        for line in fileinput.input():
            lines.append(line)

    if len(lines) > 0:
        #nt = int(lines[0])
        for index, case in enumerate(get_test_cases(lines[1:], lines_per_case), 1):
            produce_output(index, str(solve_case(case)))
