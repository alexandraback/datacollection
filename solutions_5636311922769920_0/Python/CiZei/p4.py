#!/usr/bin/env python
import sys

def print_with_divisions(arr, current_level, group_size, total_levels):
    # helper func to print an array with groups highlights for specific level
    result = []
    skipped_partitions = 0
    partitions_to_skip = group_size ** current_level
    separator = '|'
    for index, value in enumerate(arr):
        if (index != 0):
            if skipped_partitions == partitions_to_skip:
                skipped_partitions = 0
                result.append(separator)
            else:
                result.append(' ')
        skipped_partitions += 1
        result.append('{:2}'.format(value))
    print ' '.join(result)


def split_arr(arr, group_size):
    # split array into sub-groups
    return [arr[i:i+group_size] for i in range(0, len(arr), group_size)]


def group_to_check(group_size, levels):
    return split_arr(range(group_size), levels)


def calc_index_for_sequence(position_sequence, group_size, levels):
    # K = group_size
    # C = levels
    # position_sequence = the comination of groups we want eliminate with the check
    # at a single test we can check C locations at the same time so len(sequence) should be smaller than c

    while len(position_sequence) < levels:
        # pad the position to check so we go through the exact number of levels
        position_sequence.append(position_sequence[0])

    assert levels == len(position_sequence)

    index = 0
    for level, position in enumerate(position_sequence):
        index += position * group_size**level
    return index

def print_check(index_to_check, group_size, levels):
    # helper function to print out how a check test across levels
    size = group_size ** levels
    empty_array = [' ' for i in xrange(size)]
    positions_array = [i for i in xrange(size)]
    check_array = empty_array[:]
    check_array[index_to_check] = '**'
    for i in xrange(0, levels):
        print_with_divisions(empty_array, i, group_size, levels)
    print_with_divisions(positions_array, levels, group_size, levels)
    print_with_divisions(check_array, levels, group_size, levels)


def get_solution(group_size, levels):
    check_squences = group_to_check(group_size, levels)
    result = []
    for position_sequence in check_squences:
        check_index = calc_index_for_sequence(position_sequence, group_size, levels)
        result.append(check_index)
    return result


def read_case():
    return map(int, (sys.stdin.readline().strip().split()))

def solve_from_input():
    case_count = int(sys.stdin.readline())
    for i in range(1, case_count+1):
        k, c, s = read_case()
        solution_steps = get_solution(k, c)
        result = 'IMPOSSIBLE'
        if len(solution_steps) <= s:
            result = ' '.join(map(lambda x:str(x+1), solution_steps))
        print 'Case #{}: {}'.format(i, result)

if __name__ == '__main__':
    solve_from_input()



