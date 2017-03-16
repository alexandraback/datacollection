
import os
from os import path
import argparse
from pprint import pprint
from bisect import bisect

def main():
    args = parse_arguments()
    parse_and_solve(args.input, args.output)

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'),
                        nargs='?', default='input.txt', help='input file')
    parser.add_argument('output', type=argparse.FileType('w'),
                        nargs='?', default='output.txt', help='output file')

    return parser.parse_args()

def parse_and_solve(input, output):
    content = input.read()

    cases = parse_input(content)

    solutions = [solve(case) for case in cases]

    formatted_solutions = [format_solution(solution, i) for i, solution in enumerate(solutions)]
    joined_solutions = '\n'.join(formatted_solutions)

    output.write(joined_solutions)

def parse_input(input):
    numbers = [float(x) for x in input.split()]
    numbers.reverse()

    cases_count = numbers.pop()

    cases =[]
    for i in xrange(int(cases_count)):
        blocks_count = numbers.pop()
        naomi_blocks = [numbers.pop() for _ in xrange(int(blocks_count))]
        ken_blocks = [numbers.pop() for _ in xrange(int(blocks_count))]
        cases.append((naomi_blocks, ken_blocks))

    assert(len(numbers) == 0)

    return cases

def solve(case):
    naomi_blocks, ken_blocks = case

    naomi_blocks.sort()
    ken_blocks.sort()

    deceitful_war_solution = solve_deceitful_war(naomi_blocks, ken_blocks)
    war_solution = solve_war(naomi_blocks, ken_blocks)

    return deceitful_war_solution, war_solution

def solve_deceitful_war(naomi_blocks, ken_blocks):
    naomi_blocks = naomi_blocks[:]
    ken_blocks = ken_blocks[:]
    naomi_score = 0
    while len(naomi_blocks) > 0:
        if ken_blocks[-1] > naomi_blocks[-1]:
            naomi_blocks.pop(0)
            ken_blocks.pop(-1)
        else:
            naomi_blocks.pop(-1)
            ken_blocks.pop(-1)
            naomi_score += 1

    return naomi_score

def solve_war(naomi_blocks, ken_blocks):
    naomi_blocks = naomi_blocks[:]
    ken_blocks = ken_blocks[:]
    naomi_score = 0
    while len(naomi_blocks) > 0:
        naomi_block = naomi_blocks.pop()
        ken_block_index = bisect(ken_blocks, naomi_block)
        if ken_block_index == len(ken_blocks):
            ken_blocks.pop(0)
            naomi_score += 1
        else:
            ken_blocks.pop(ken_block_index)

    return naomi_score

def format_solution(solution, index):
    format = 'Case #%d: %d %d'
    return format % (index + 1, solution[0], solution[1])

if __name__ == '__main__':
    main()
