#!/usr/bin/env python3
import sys
import argparse

def check_if_piece_exceeds_this_dimension(dimension, omino_size):
    if omino_size <= 2:
        return False

    for i in range(1, omino_size+1):
        left = i
        right = omino_size + 1 - i
        if min(left, right) > dimension:
            return True
    return False

def check_if_can_cut_off(row_size, column_size, omino_size):
    if omino_size <= 2:
        return False
    max_dimension = max(column_size, row_size)
    min_dimension = min(column_size, row_size)

    for i in range(1, omino_size+1):
        left = i
        right = omino_size + 1 - i
        if min(left, right) != min_dimension:
            continue
        if max(left, right) < 3:
            continue
        return True
    return False

def process_instance(instance):
    omino_size = instance['omino_size']
    number_of_columns = instance['number_of_columns']
    number_of_rows = instance['number_of_rows']
    if omino_size >= 7:
        return 'RICHARD'

    if omino_size > number_of_columns * number_of_rows:
        return 'RICHARD'

    if number_of_columns * number_of_rows % omino_size != 0:
        return 'RICHARD'

    min_dimension = min(number_of_rows, number_of_columns)
    if check_if_piece_exceeds_this_dimension(min_dimension, omino_size):
        return 'RICHARD'

    if check_if_can_cut_off(number_of_rows, number_of_columns, omino_size):
        return 'RICHARD'

    return 'GABRIEL'

def parse_line(line):
    line = line.strip().split(' ')
    omino_size, number_of_rows, number_of_columns = [int(x) for x in line]

    instance = {}
    instance['omino_size'] = omino_size
    instance['number_of_rows'] = number_of_rows
    instance['number_of_columns'] = number_of_columns
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
        instances = tuple(parse_line(line) for line in file_)
    return (number_of_instances, instances)

def print_status(i, total):
    print_string = "\rProcessing {}/{} instances".format(i+1, total)
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
