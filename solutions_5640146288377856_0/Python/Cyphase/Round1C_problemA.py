"""
Therefore:

Brat will always move the ship to make you miss if possible; once the
ship is hit, it's stuck attached to that cell.


"""
from __future__ import print_function

import sys

def get_input():
    num_cases = int(sys.stdin.readline())

    for line in sys.stdin:
        R, C, W = [int(i) for i in line.split()]
        yield (R, C, W)


def solve(cases):
    for R, C, W in cases:
        assert 1 <= R <= 20
        assert 1 <= W <= C <= 10

        # A value for C we can use for starting guesses from far left
        tmpC = C - (W - 1)

        # for W == 4
        # ___x___x___x___x___x___
        # ___x___x___x___x___x___x
        # ___x___x___x___x___x___x_
        num_guesses_to_clear_row = C // W

        # Last clearing guess pins the ship
        num_guesses_to_pin_ship = num_guesses_to_clear_row * R

        num_guesses_to_sink_ship = W if C % W else (W - 1)

        yield num_guesses_to_pin_ship + num_guesses_to_sink_ship


def main():
    cases = get_input()
    answers = solve(cases)

    for case_num, a in enumerate(answers, 1):
        print('Case #%d: %s' % (case_num, a))


if __name__ == '__main__':
    main()
