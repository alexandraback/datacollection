"""
Created on Apr 8, 2016

@author: umnik700@gmail.com
"""

# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'

# INPUT_FILE = 'B-small-attempt0.in'
# OUTPUT_FILE = 'B-small-attempt0.out'

INPUT_FILE = 'B-large.in'
OUTPUT_FILE = 'B-large.out'

def process_case(v):
    print v
    
    if('-' not in v):
        return 0
    if('+' not in v):
        return 1
    if('-+' == v):
        return 1
    if('+-' == v):
        return 2
    if('+' == v[-1]):
        if('+' not in v.rstrip('+')):
            return 1
        else:
            return process_case(v.rstrip('+'))
    else:
        if('-' not in v.rstrip('-')):
            return 2
        else:
            return 2 + process_case(v.rstrip('-'))


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

        tests += [line.strip()]
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
    for test in tests:
        case_number += 1

        result = process_case(test)

        print "Case #{0}: {1}".format(case_number, result)
        o.write("Case #{0}: {1}\n".format(case_number, result))
