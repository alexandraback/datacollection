__author__ = 'Bill'

# developed with python3.3 + numpy

import sys, time, numpy as np


def parse_case(file):
    return map(int, file.readline().split())

def process_case(case):
    a,b,k = case
    result = 0

    for i in range(a):
        for j in range(b):
            if i & j < k:
                result += 1

    return result

if __name__ == '__main__':
    t0 = time.clock()

    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        filename = "sample.in"

    input_file = open(filename, "r")
    output_file = open(filename.replace('in','out'), "w")
    case_count = int(input_file.readline())
    for i in range(case_count):
        result = process_case(parse_case(input_file))
        output_line = 'Case #%d: %s\n' % (i+1, result)
        print(output_line)
        output_file.writelines(output_line)

    input_file.close()
    output_file.close()

    print('Total Time: %s' % str(time.clock() - t0))