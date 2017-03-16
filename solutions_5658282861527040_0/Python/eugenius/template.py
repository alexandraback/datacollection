"""
Author: Eugene Yurtsev
"""
import sys
import math

debug=False

def parse_case(stream):
    specs = stream.readline()
    specs = map(int, specs.split(' '))
    return specs

def solve_case(specs):
    count = 0
    A, B, K = specs
    for x in range(A):
        for y in range(B):
            if x & y < K:
                count += 1
    return count

def main(stream):
    num_cases = int(stream.readline())
    for case in range(num_cases):
        specs = parse_case(stream)
        print 'Case #{}: {}'.format(case+1, solve_case(specs))
    if debug:
        print '-'*40
        print 'solution'
        print ''.join(stream.readlines())

if __name__ == '__main__':
    if debug:
        with open('test.in', 'r') as stream:
            main(stream)
    else:
        main(sys.stdin)
