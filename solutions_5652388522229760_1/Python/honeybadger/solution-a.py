"""
Created on Apr 9, 2016

@author: umnik700@gmail.com
"""

from itertools import count

# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'

# INPUT_FILE = 'A-small-attempt0.in'
# OUTPUT_FILE = 'A-small-attempt0.out'

INPUT_FILE = 'A-large.in'
OUTPUT_FILE = 'A-large.out'

def process_case(n):
    
    prev_value = None
    digits_seen = set()
    for i in xrange(1, 10000000):
        v = n * i
        if(prev_value == v):
            return 'INSOMNIA'
        for j in list(str(v)):
            digits_seen.add(j)
        
        if(len(digits_seen) == 10):
            return v

    return 'INSOMNIA'


total_tests = None
tests = []

with open(INPUT_FILE, 'rU') as f:

    input_data = list(f)
    index = 0
    while index < len(input_data):

        print 'index', index
        line = input_data[index].strip()

        if(total_tests is None):
            total_tests = int(line)
            print 'total_tests', total_tests
            index += 1
            continue

        tests += [int(line.strip())]
        index += 1

print tests
if(total_tests != len(tests)):
    print 'tests', len(tests)
    raise Exception('invalid number of tests')

print '-' * 70
print 'input data'
print '-' * 70
for test in tests:
    print test
print '-' * 70

case_number = 0

with open(OUTPUT_FILE, 'wb') as o:
    for n in tests:
        case_number += 1

        result = process_case(n)

        print "Case #{0}: {1}".format(case_number, result)
        o.write("Case #{0}: {1}\n".format(case_number, result))
