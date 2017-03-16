"""
Created on Apr 9, 2016

@author: umnik700@gmail.com
"""

# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'

# INPUT_FILE = 'D-small-attempt0.in'
# OUTPUT_FILE = 'D-small-attempt0.out'

INPUT_FILE = 'D-large.in'
OUTPUT_FILE = 'D-large.out'


def process_case(k, c, s):
    print k, c, s

    # this is enough for "small" dataset
    # because if the first tile is L in the original sequence
    # then the first K tiles in the result sequence would contain
    # the whole original sequence
    #
    # if the first tile is G in origial sequence
    # then the very first tile in the result sequence would also be G
    #
    # and we are guaranteed to have s==k
    if(s == k):
        return ' '.join([str(i) for i in xrange(1, s + 1)])

    return 'IMPOSSIBLE'


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

        k, c, s = [int(i) for i in line.strip().split(' ')]
        tests += [(k, c, s)]
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
    for k, c, s in tests:
        case_number += 1

        result = process_case(k, c, s)

        print "Case #{0}: {1}".format(case_number, result)
        o.write("Case #{0}: {1}\n".format(case_number, result))
