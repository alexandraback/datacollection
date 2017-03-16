#!/usr/bin/env python3
import sys
import argparse
from math import ceil
from collections import namedtuple

def calculate_time_to_eat(pancakes, eating_time):
    time = [ceil(pancake/eating_time) - 1 for pancake in pancakes]
    time = sum(time) + eating_time
    return time

def process_instance(instance):
    pancakes = instance['diners']
    max_val = max(pancakes) + 1
    return min([calculate_time_to_eat(pancakes, i) for i in range(1, max_val)])

def parse_line(number_of_diners, diners):
    instance = {}

    number_of_diners = number_of_diners.strip()
    diners = diners.strip('\n').split(' ')

    # cleanup number of diners
    number_of_diners = int(number_of_diners)
    instance['number_of_diners'] = number_of_diners

    # cleanup diners
    diners = [int(x) for x in list(diners)]
    instance['diners'] = diners

    diners_length = len(diners)
    if number_of_diners != diners_length:
        print("num diners = {}|list = {}".format(number_of_diners, diners_length))
        raise Exception("Num diners does not equal number of diners")
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
        instances = tuple(instances)
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
        print("number of instances={} != number of instances parsed={}"
              .format(number_of_instances, len(instances)))
        raise Exception('Invalid number of instances')

    solutions = []
    for i, instance in enumerate(instances):
        print_status(i, number_of_instances)
        solution = process_instance(instance)
        solutions.append(solution)
    print("\nFinished Processing!")

    get_output_from_solutions(args.output_file_name, solutions)

    print("Done!")
