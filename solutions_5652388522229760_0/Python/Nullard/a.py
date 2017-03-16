#!/bin/env python

input_file = None

import glob
import os
import sys

def main():
    cases = readone(int)
    output = []
    for case_num in range(1, cases + 1):
        result = None
        ### Begin solution code
        base = readone(int)
        if base == 0: result = 'INSOMNIA'
        else: 
            digits = map(str, range(10))
            counter = 0
            while len(digits):
                counter += 1
                found = set()
                for digit in digits:
                    if digit in str(base * counter):
                        found.add(digit)
                for digit in found:
                    digits.remove(digit)
            result = str(base * counter)

        ### End solution code
        output.append('Case #%d: ' % (case_num,) + str(result))
    output_file = open(output_filename, 'w')
    output_file.write('\n'.join(output))
    output_file.close()
    print '\n'.join(output)

def readone(t):
    line = input_file.readline()
    assert(len(line.split()) == 1)
    return t(line.strip())

def readmany(t):
    return map(t, input_file.readline().split())

if __name__ == '__main__':
    input_file = sys.stdin
    problem = os.path.split(__file__)[1][0].upper()
    output_filename = 'test.out'
    inputs = glob.glob(os.path.expanduser('~') + '/Downloads/' + problem + '-*.in')
    newest = max(inputs, key=os.path.getctime)
    input_filename = os.path.split(newest)[1]
    output_filename = problem + '-' + input_filename.split('-')[1] + '.out'
    input_file = open(newest)
    
    output_filename = problem + '-'
    
    main()
    input_file.close()