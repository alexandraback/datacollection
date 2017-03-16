'''
Created on Apr 11, 2014

@author: sergey

Problem B. Cookie Clicker Alpha
'''

import os

def get_data(fullpath):
    if(not os.path.exists(fullpath)):
        print 'file does not exist'
        return []

    result = []
    is_first_line = True
    number_of_test_cases = 0
    is_in_test_case = False
    line_in_test = 0
    with open(fullpath, 'r') as input_file:
        for line in input_file:

            if(is_first_line):
                is_first_line = False
                t = int(line)
                if(t >= 1 and t <= 100):
                    print 'number of test cases', t
                    continue

                print 'invalid number of test cases', t
                return []



            c, f, x = [float(i) for i in line.split(' ')]
            print 'c', c
            print 'f', f
            print 'x', x

            if(not (c >= 1 and c <= 10000 and f >= 1 and f <= 100 and x >= 1 and x <= 100000)):
                print 'invalid c or f or x'
                return []

            result += [{
                        'c': c,
                        'f': f,
                        'x': x
                        }]

    if(t != len(result)):
        print 'expected', t, 'tests, instead got', len(result)
        return []

    return result

def get_next_farm(c, f, x, cookie_production, time_to_get_previous_farms):
    new_production = cookie_production + f
    time_to_get_new_farm = (c / cookie_production) + time_to_get_previous_farms
    total_time = time_to_get_new_farm + (x / new_production)
    return new_production, time_to_get_new_farm, total_time

def main():

#     input_filename = 'B-small-attempt0.in'
#     output_filename = 'B-small-attempt0.out'

    input_filename = 'B-large.in'
    output_filename = 'B-large.out'

    data = get_data(input_filename)
    for item in data:
        print item

    print '-' * 75

    with open(output_filename, 'wb') as output_file:

        case_number = 0
        for item in data:

            c = item['c']
            f = item['f']
            x = item['x']

            case_number += 1

            cookie_production = 2.0
            total_seconds = 0.0
            time_to_get_previous_farms = 0.0

            result = x / cookie_production
            while(True):
                cookie_production, time_to_get_previous_farms, total_seconds = get_next_farm(c, f, x, cookie_production, time_to_get_previous_farms)
                if(result < total_seconds):
                    # no more farms
                    break
                result = total_seconds

            print 'Case #%d: %.7f' % (case_number, result)
            output_file.write('Case #%d: %.7f\n' % (case_number, result))

if __name__ == "__main__":
    main()
