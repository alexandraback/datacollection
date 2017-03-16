"""
Author: Eugene Yurtsev
"""
import sys
import math

STDIN = sys.stdin
num_cases = int(STDIN.readline())

def parse_case():
    specs = STDIN.readline()
    specs = map(int, specs.split(' '))
    return specs

def solve_case(R, C, M):
    """
    We'll place the click in the bottom right corner.

    Fill mines in an order to reduce the longer dimension.

    Returns
    --------
    -1 if impossible
    Otherwise string with configuration
    """
    total = R * C
    free_spots = total - M # positions free of mines

    if free_spots <= 0:
        return -1
    elif free_spots == 1:
        # If only one free spot then the arrangement is obvious.
        field = [['*' for c in range(C)] for r in range(R)]
        field[-1][-1] = 'c'
        field = '\n'.join([''.join(f) for f in field])
        return field
    # Edge cases in 1D
    if R == 1:
        field = ['.' for c in range(C)]
        for m in range(M):
            field[m] = '*'
        field[-1] = 'c'
        return ''.join(field)
    if C == 1:
        field = ['.' for r in range(R)]
        for m in range(M):
            field[m] = '*'
        field[-1] = 'c'
        return '\n'.join(field)
    # Some special cases when it's impossible to arrange the mines
    if R == 2 or C == 2:
        if M % 2 == 1: return -1
    if free_spots in (2, 3, 5, 7):
        return -1

    # If we got all the way here, then we're in the general case
    # and need to fill the mines in the correct order

    field = [['.' for c in range(C)] for r in range(R)]
    field[-1][-1] = 'c'

    current_r = 0
    current_c = 0

    mines_left = M

    while mines_left > 0:
        small_dimension = 'row' if (R-current_r) < (C-current_c) else 'col'
        mines_to_place = (R-current_r) if small_dimension == 'row' else (C-current_c)
        if mines_to_place > mines_left:
            if mines_to_place == mines_left + 1: # Special case
                mines_to_place = mines_left - 1

                # Place a single mine 
                if small_dimension == 'row':
                    field[current_r][current_c+1] = '*'
                else:
                    field[current_r+1][current_c] = '*'

                mines_left -= 1
            else:
                mines_to_place = mines_left

        #print '\n'.join([''.join(f) for f in field])

        if small_dimension == 'row':
            for i in range(mines_to_place):
                field[current_r+i][current_c] = '*'
            current_c += 1
        else:
            for i in range(mines_to_place):
                field[current_r][current_c+i] = '*'
            current_r += 1

        mines_left -= mines_to_place


    field = '\n'.join([''.join(f) for f in field])
    return field

for case in range(num_cases):
    R, C, M = parse_case()
    solution = solve_case(R, C, M)
    if solution == -1:
        solution = "Impossible"
    print 'Case #{}:\n{}'.format(case+1, solution)
