#!/bin/env python

input_file = None

import os
import sys
import math


def main():
    cases = readone(int)
    output = []
    for case_num in range(1, cases + 1):
        result = None
        ### Begin solution code
        c, d, v = readmany(int)
        denoms = readmany(int)
        added = 0
        if denoms[0] != 1:
            denoms.insert(0, 1)
            added = 1
        max_v = 0
        while max_v < v:
            if not denoms:
                # print math.ceil(math.log((v - max_v) / (max_v + 1), c + 1))
                # added += math.ceil(math.log((v - max_v) / (max_v + 1), c + 1))
                left = v - max_v
                next = max_v + 1.0
                added += math.ceil(math.log(left / next + 1, c + 1))

                break
            if denoms[0] <= max_v + 1:
                max_v += c * denoms[0]
                denoms.pop(0)
            else:
                max_v += c * (max_v + 1)
                added += 1

        result = int(added)
        ### End solution code
        output.append('Case #%d: ' % (case_num,) + str(result))
    output_file = open(output_filename, 'w')
    output_file.write('\n'.join(output))
    output_file.close()
    # if output_filename.endswith('sample.out'):
    #     their_output = open('C-their-sample.out')
    #     for line_num, line in enumerate(output):
    #         their_line = their_output.readline().strip()
    #         if line == their_line:
    #             print line
    #         else:
    #             print line_num, ' yours :', line
    #             print line_num, ' theirs:', their_line
    #     their_output.close()
    # else:
    #     print '\n'.join(output)
    print '\n'.join(output)

def readone(t):
    line = input_file.readline()
    assert(len(line.split()) == 1)
    return t(line.strip())

def readmany(t):
    return map(t, input_file.readline().split())

if __name__ == '__main__':
    input_file = sys.stdin
    output_filename = 'test.out'
    if os.path.exists('C-large.in'):
        input_file = open('C-large.in')
        output_filename = 'C-large.out'
    elif os.path.exists('C-small.in'):
        input_file = open('C-small.in')
        output_filename = 'C-small.out'
    elif os.path.exists('C-sample.in'):
        input_file = open('C-sample.in')
        output_filename = 'C-sample.out'
    main()
    input_file.close()