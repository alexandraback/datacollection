'''
Created on May 3, 2014

@author: sergey

Problem B. New Lottery Game
'''

import os


def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    line_in_test = 0
    number_of_test_cases = 0
    with open(fullpath, 'r') as input_file:
        for line in input_file:

            print '---', line_in_test, line
            if(is_first_line):
                is_first_line = False
                number_of_test_cases = int(line)
                if(number_of_test_cases >= 1 and number_of_test_cases <= 100):
                    line_in_test = 1
                    continue

                print 'invalid number of test cases', number_of_test_cases
                return []

            a, b, k = [int(i) for i in line.strip().split(' ')]
            if(not(a >= 1 and a <= 1000000000 and
                   b >= 1 and b <= 1000000000 and
                   k >= 1 and k <= 1000000000)):
                print "invalid a or b or k", a, b, k
                return []
            result += [{
                        'a': a,
                        'b': b,
                        'k': k
                         }]


    print 'expected', number_of_test_cases, 'test cases, got', len(result)
    if(number_of_test_cases != len(result)):
        return []

    return result

def get_result(a, b, k):

    result = 0
    for i in xrange(a):
        for j in xrange(b):
            s = i & j
            if(s < k):
                result += 1
    return result

def main():

    input_filename = 'B-small-attempt0.in'
    output_filename = 'B-small-attempt0.out'

    data = get_data(input_filename)
    for item in data:
        print item

    print '-' * 75

    with open(output_filename, 'wb') as output_file:
        case_number = 0
        for item in data:
            case_number += 1

            result = get_result(item['a'], item['b'], item['k'])
            print 'Case #%d: %d' % (case_number, result), item
            output_file.write('Case #%d: %d\n' % (case_number, result))

if __name__ == "__main__":
    main()
