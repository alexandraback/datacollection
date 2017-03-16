#!/usr/bin/env python3
import sys
import argparse

def multiply(x, y):
    x_is_negative = False
    y_is_negative = False

    if len(x) == 2:
        x_is_negative = True
        x = x[1]
    if len(y) == 2:
        y_is_negative = True
        y = y[1]

    value = multiply_only_positive_x_y(x, y)

    if ((x_is_negative and not y_is_negative)
        or (not x_is_negative and y_is_negative)):
        if len(value) == 2:
            value = value[1]
        else:
            value = "-{}".format(value)
    return value

def multiply_only_positive_x_y(x, y):
    if x == '1':
        return y
    if y == '1':
        return x

    key = {
            ('i','i') : '-1',
            ('i','j') : 'k',
            ('i','k') : '-j',

            ('j','i') : '-k',
            ('j','j') : '-1',
            ('j','k') : 'i',

            ('k','i') : 'j',
            ('k','j') : '-i',
            ('k','k') : '-1',
          }
    return key[(x,y)]

def process_instance(instance):
    substring = instance['substring']
    number_of_characters = instance['number_of_characters']
    number_of_times_to_repeat = instance['number_of_times_to_repeat']
    total_number_of_characters = number_of_characters * number_of_times_to_repeat

    # detect i
    i_substring = '1'
    for i in range(total_number_of_characters):
        i_substring = multiply(i_substring, substring[i%number_of_characters])
        if i_substring == 'i':
            break
    else:
        print("No i")
        return "NO"

    # detect k
    k_substring = '1'
    for k in reversed(range(i+1, total_number_of_characters)):
        k_substring = multiply(substring[k%number_of_characters], k_substring)
        if k_substring == 'k':
            break
    else:
        print("No k")
        return "NO"

    # check middle is j
    j_substring = '1'
    for j in range(i+1, k):
        j_substring = multiply(j_substring, substring[j%number_of_characters])

    if j_substring == 'j':
        return "YES"
    print("No j")
    print(j_substring)
    return "NO"

def parse_line(metadata, substring):
    substring = substring.strip()
    metadata = metadata.strip().split(' ')

    instance = {}

    # cleanup metadata
    number_of_characters, number_of_times_to_repeat = [int(x) for x in metadata]
    instance['number_of_characters'] = number_of_characters
    instance['number_of_times_to_repeat'] = number_of_times_to_repeat

    # cleanup substring
    instance['substring'] = substring

    substring_length = len(substring)
    if number_of_characters != substring_length:
        print("num char = {}|substring = {}".format(
              number_of_characters, substring_length))
        warning = "substring does not have the correct amount of characters"
        raise Exception(warning)
    return instance

def clean_solution(i, solution):
    solution = "Case #{}: {}".format(i, solution)
    print(solution)
    return solution

def get_output_from_solutions(file_name, solutions):
    lines = [clean_solution(i+1, solution) + '\n'
             if i != len(solutions) - 1
             else
             clean_solution(i+1, solution)
             for i, solution in enumerate(solutions)
            ]
    with open(file_name, 'w', encoding='utf-8') as file_:
        file_.writelines(lines)

def parse_file(file_name):
    with open(file_name, mode = 'r', encoding='utf-8') as file_:
        number_of_instances = int(file_.readline())
        lines = [line for line in file_]

        instances = []
        for i in range(number_of_instances):
            instance = parse_line(lines[2*i], lines[2*i+1])
            instances.append(instance)
    return (number_of_instances, instances)

def print_status(i, total):
    print_string = "\rProcessing {}/{} instances ".format(i+1, total)
    sys.stdout.write(print_string)
    sys.stdout.flush()

if __name__ == '__main__':
    description='Process standing ovation problem'
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('input_file_name', type=str, help='File to process')
    parser.add_argument('--output_file_name', type=str, help='File to output',
                        default='output')
    args = parser.parse_args()

    number_of_instances, instances = parse_file(args.input_file_name)

    if number_of_instances != len(instances):
        print("number of instances != number of instances parsed")
        raise Exception('Invalid number of instances')

    solutions = []
    for i, instance in enumerate(instances):
        print_status(i, number_of_instances)
        solution = process_instance(instance)
        solutions.append(solution)
    print("\nFinished Processing!")

    get_output_from_solutions(args.output_file_name, solutions)

    print("Done!")
