#!/usr/bin/env python3
import sys
import argparse

def process_instance(instance):
    number_of_people_standing = 0
    number_of_people_to_invite = 0

    for i, number_of_people in enumerate(instance['audience']):
        if number_of_people == 0:
            continue
        if number_of_people_standing < i:
            number_of_people_to_invite += i - number_of_people_standing
            number_of_people_standing = i
        number_of_people_standing += number_of_people

    return number_of_people_to_invite

def parse_line(line):
    line = line.strip()
    instance = {}
    max_shyness, audience = line.split()

    # cleanup max shyness
    max_shyness = int(max_shyness)
    instance['max_shyness'] = max_shyness

    # cleanup audience
    audience = [int(x) for x in list(audience)]
    instance['audience'] = audience

    shyness_entries = len(audience)
    if max_shyness + 1 != shyness_entries:
        print("max shyness = {}|list = {}".format(max_shyness, shyness_entries))
        raise Exception("Max shyness does not equal number of shyness levels")
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
