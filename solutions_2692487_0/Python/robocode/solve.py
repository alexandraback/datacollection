#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      hagai
#
# Created:     04/05/2013
# Copyright:   (c) hagai 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()

import os
from os import path
import argparse
from pprint import pprint

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
    print joined_solutions

def parse_input(input):
    numbers = [int(x) for x in input.split()]
    numbers.reverse()

    cases_count = numbers.pop()

    cases =[]
    for i in xrange(cases_count):
        aramin = numbers.pop()
        motes_count = numbers.pop()
        motes = []
        for j in xrange(motes_count):
            mote = numbers.pop()
            motes.append(mote)

        case = (aramin, motes)
        cases.append(case)

    assert(len(numbers) == 0)

    return cases

def solve(case):
    aramin, motes = case
    motes.sort()

    aramin, motes = try_absord_all(aramin, motes)
    if len(motes) == 0:
        return 0
    else:
        # delete approach
        delete_moves = len(motes)
        # add approach
        smaller = aramin - 1
        if smaller == 0:
            add_moves = 999999999999999 #infinity
        else:
            motes.insert(0, smaller)
            add_moves = solve((aramin, motes)) + 1
        return min(delete_moves, add_moves)


def try_absord_all(aramin, motes):
    while len(motes) > 0:
        aramin, motes, absorbed = try_absorb_one(aramin, motes)
        if not absorbed:
            break

    return aramin, motes


def try_absorb_one(aramin, motes):
    if aramin > motes[0]:
        aramin += motes[0]
        motes.pop(0)
        return (aramin, motes, True)
    else:
        return (aramin, motes, False)

def format_solution(solution, index):
    format = 'Case #%d: %s'
    return format % (index + 1, str(solution))

if __name__ == '__main__':
    main()
