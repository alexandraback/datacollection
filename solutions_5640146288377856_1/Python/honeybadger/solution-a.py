"""
Created on May 10, 2015

@author: umnik700@gmail.com
"""

# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'

# INPUT_FILE = 'A-small-attempt0.in'
# OUTPUT_FILE = 'A-small-attempt0.out'

INPUT_FILE = 'A-large.in'
OUTPUT_FILE = 'A-large.out'

total_tests = None
tests = []


def process_test(r, c, w):

    score = -1

    if(r * c == w):
        return w

    if(w == 1):
        return r * c
    
    if(c == w):
        return (r - 1) + w
    
    # go through all rows except the one where the ship is
    score = (r - 1) * (c / w)

    # final row
    if((c % w) == 0):
        score += ((c / w) + (w - 1))
    else:
        score += ((c / w) + w)
        

    print 'process_test', (r, c, w)
    return score

with open(INPUT_FILE) as f:

    input_data = list(f)
    index = 0
    while index < len(input_data):

        print 'index', index

        line = input_data[index].strip()
        if(not line):
            index += 1
            continue

        if(total_tests is None):
            total_tests = int(line)
            print 'total_tests', total_tests
            index += 1
            continue

        r, c, w = [int(i) for i in line.strip().split(' ')]

        tests += [(r, c, w)]
        index += 1

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
    for r, c, w in tests:
        case_number += 1

        result = process_test(r, c, w)

        print "Case #%d: %d" % (case_number, result)
        o.write("Case #%d: %d\n" % (case_number, result))
