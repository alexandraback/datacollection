#!/usr/bin/python
#flake8: noqa

import sys
from collections import defaultdict

NUMBERS = [
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
]

PASS_1 = [
    (0, 'Z'),
    (2, 'W'),
    (4, 'U'),
    (6, 'X'),
    (8, 'G')
]

PASS_2 = [
    (1, 'O'),
    (3, 'T'),
    (5, 'F'),
    (7, 'V')
]

# build letter counts
LETTERS = []

def solve(S, i):
    """Main solution"""
    # Build letter counts
    digits = []
    letter_counts = defaultdict(int)
    for letter in S:
        letter_counts[letter] += 1

    # print letter_counts

    # Pass 1
    zeros = letter_counts['Z']
    digits += [0] * zeros
    letter_counts['Z'] -= zeros
    letter_counts['E'] -= zeros
    letter_counts['R'] -= zeros
    letter_counts['O'] -= zeros

    twos = letter_counts['W']
    digits += [2] * twos
    letter_counts['T'] -= twos
    letter_counts['W'] -= twos
    letter_counts['O'] -= twos

    fours = letter_counts['U']
    digits += [4] * fours
    letter_counts['F'] -= fours
    letter_counts['O'] -= fours
    letter_counts['U'] -= fours
    letter_counts['R'] -= fours

    sixes = letter_counts['X']
    digits += [6] * sixes
    letter_counts['S'] -= sixes
    letter_counts['I'] -= sixes
    letter_counts['X'] -= sixes

    eights = letter_counts['G']
    digits += [8] * eights
    letter_counts['E'] -= eights
    letter_counts['I'] -= eights
    letter_counts['G'] -= eights
    letter_counts['H'] -= eights
    letter_counts['T'] -= eights

    # pass 2
    ones = letter_counts['O']
    digits += [1] * ones
    letter_counts['O'] -= ones
    letter_counts['N'] -= ones
    letter_counts['E'] -= ones

    threes = letter_counts['T']
    digits += [3] * threes
    letter_counts['T'] -= threes
    letter_counts['H'] -= threes
    letter_counts['R'] -= threes
    letter_counts['E'] -= threes
    letter_counts['E'] -= threes

    fives = letter_counts['F']
    digits += [5] * fives
    letter_counts['F'] -= fives
    letter_counts['I'] -= fives
    letter_counts['V'] -= fives
    letter_counts['E'] -= fives

    sevens = letter_counts['V']
    digits += [7] * sevens
    letter_counts['S'] -= sevens
    letter_counts['E'] -= sevens
    letter_counts['V'] -= sevens
    letter_counts['E'] -= sevens
    letter_counts['N'] -= sevens

    # pass 3
    nines = letter_counts['I']
    digits += [9] * nines
    letter_counts['N'] -= nines
    letter_counts['I'] -= nines
    letter_counts['N'] -= nines
    letter_counts['E'] -= nines

    # for letter, count in letter_counts.iteritems():
    #     print letter, count

    digits.sort()

    return "".join(map(str, digits))

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "A-large.in" if no command line args
filename = "A-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        S = input_file.readline().strip()
        result = solve(S, i)
        output_case(i, result)
