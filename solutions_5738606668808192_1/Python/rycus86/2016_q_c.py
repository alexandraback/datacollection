__author__ = 'rycus86'

import os
import math

# Problem C: Coin Jam

FILENAME = 'res/2016_q_c.large'
OUTPUT_FILE = '%s.out' % FILENAME


LIMIT = 100


def solve(n, j):
    result_lines = []

    max_number = 1 << n
    number = (1 << (n - 1)) + 1

    while number < max_number and len(result_lines) < j:
        binary = bin(number)[2:]

        divisors = []

        for base in xrange(2, 10+1):
            converted = long(binary, base)

            div = get_small_divisor(converted)

            if div is not None:
                divisors.append(str(div))

            else:
                break

        else:
            result_lines.append('%s %s' % (binary, ' '.join(divisors)))

        number += 2

    return '\n'.join(result_lines)


def get_small_divisor(num):
    if num % 2 == 0:
        return 2

    for div in xrange(3, LIMIT, 2):
        if num % div == 0:
            return div


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                N, J = map(int, input_file.readline().split())
                result = solve(N, J)

                print 'Case #%d:\n%s' % (case, result)
                print >> output_file, 'Case #%d:\n%s' % (case, result)
