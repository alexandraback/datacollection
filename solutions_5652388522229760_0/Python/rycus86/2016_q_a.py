__author__ = 'rycus86'

import math

# Problem A: Counting Sheep

FILENAME = 'res/2016_q_a.small'
OUTPUT_FILE = '%s.out' % FILENAME

MAX = math.pow(2, 63)


def solve(n):
    if n <= 0:
        return 'INSOMNIA'

    seen = set()
    current = n

    while current < MAX:
        string = str(current)

        for char in string:
            seen.add(char)

        if len(seen) == 10:
            return current

        current += n

    return 'INSOMNIA'


if __name__ == '__main__':
    with open(FILENAME) as input_file:
        with open(OUTPUT_FILE, 'w') as output_file:
            num_cases = int(input_file.readline())
            print 'Solving %d test cases' % num_cases

            for case in xrange(1, num_cases + 1):
                N = int(input_file.readline().strip())
                result = solve(N)

                print 'Case #%d: %s' % (case, result)
                print >> output_file, 'Case #%d: %s' % (case, result)
