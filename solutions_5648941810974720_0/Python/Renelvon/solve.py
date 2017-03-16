#!/usr/bin/env python3
import sys
import collections


def main():
    input_file = sys.argv[1]
    solve(input_file)


def solve(input_file):
    with open(input_file) as f_in:
        t = int(next(f_in))
        for case in range(t):
            ins = next(f_in).rstrip()
            numbers = solve_instance(ins)
            print("Case #%d: %s" % (case + 1, numbers))


def solve_instance(s):
    c = collections.Counter(s) 
    numap = (
        (0, 'Z', 'ZERO'),
        (2, 'W', 'TWO'),
        (6, 'X', 'SIX' ),
        (8, 'G', 'EIGHT'),
        (3, 'H', 'THREE',),
        (4, 'U', 'FOUR'),
        (5, 'F', 'FIVE', ),
        (7, 'V', 'SEVEN'),
        (1, 'O', 'ONE'),
        (9, 'E', 'NINE')
    )
    solution = [0] * 10
    for num, letter, word in numap:
        solution[num] = c[letter]
        for l in word:
            c[l] -= solution[num]

    strings = (str(i) * solution[i] for i in range(10))
    return ''.join(strings)


if __name__ == '__main__':
    main()
