#! /usr/bin/env python3

import sys

def solve(cs):
    s = cs[0]
    for c in cs[1:]:
        if c >= s[0]:
            s = c + s
        else:
            s = s + c

    return s

def parse(case):
    return list(case)

#################################################################

if __name__ == '__main__':
    filename = sys.argv[1]

    with open(filename) as f:
        content = f.read().strip()

    cases = content.split('\n')[1:]
    for (i, case) in enumerate(cases, 1):
        problem = parse(case)
        print('Case #', i, ': ', solve(problem), sep='')
