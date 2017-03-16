"""
Created on May 10, 2015

@author: umnik700@gmail.com
"""

# INPUT_FILE = 'test-input.txt'
# OUTPUT_FILE = 'test-output.txt'

INPUT_FILE = 'B-small-attempt1.in'
OUTPUT_FILE = 'B-small-attempt1.out'

total_tests = None
tests = []


def process_test(k, l, s, monkey_keys, target_word):

    result = -1

    print
    print 'process_test', (k, l, s, monkey_keys, target_word)

    for i in target_word:
        if(i not in monkey_keys):
            return 0

    # probability to type target word
    p = 1.0
    for i in target_word:
        p *= ((1.0 * monkey_keys.count(i) / len(monkey_keys)))
    print 'p', p

    # how many times can possibly type target word
    min_shift = 0
    for i in xrange(len(target_word)):
        remaining_word = target_word[i:]
        if(target_word.startswith(remaining_word)):
            min_shift = i
            break

    possible_number_of_target_words = s / l
    if(min_shift > 0):
#         possible_number_of_target_words = 0
#         for i in xrange(0, s, min_shift):
#             if((i + l) <= s):
#                 possible_number_of_target_words += 1
        possible_number_of_target_words = 1 + ((s - l) / min_shift)

    print 'possible_number_of_target_words', possible_number_of_target_words

    expected_targets = p * possible_number_of_target_words
    print 'expected_targets', expected_targets
    
    bring_bananas = 1.0 * possible_number_of_target_words
    
    keep_bananas = bring_bananas
    if(expected_targets > 0.000001):
        print bring_bananas, expected_targets, bring_bananas - expected_targets
        keep_bananas = bring_bananas - expected_targets

    result = keep_bananas

    print result, keep_bananas
    return result

with open(INPUT_FILE) as f:

    input_data = list(f)
    index = 0
    while index < len(input_data):

        monkey_keys = ''
        target_word = ''

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

        k, l, s = [int(i) for i in line.strip().split(' ')]
        index += 1
        line = input_data[index].strip()
        monkey_keys = line

        index += 1
        line = input_data[index].strip()
        target_word = line

        tests += [(k, l, s, monkey_keys, target_word)]
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
    for k, l, s, monkey_keys, target_word in tests:
        case_number += 1

        result = process_test(k, l, s, monkey_keys, target_word)

        print "Case #%d: %.7f" % (case_number, result)
        o.write("Case #%d: %.7f\n" % (case_number, result))
