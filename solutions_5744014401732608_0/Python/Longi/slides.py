#!/usr/bin/python3

import sys
import numpy


def main():
    with open(sys.argv[1]) as input_file:
        content = [line.strip('\n') for line in input_file.readlines()]

    case_count = int(content[0])

    with open('output', 'w') as output_file:
        for case_number in range(1, case_count + 1):
            b = int(content[case_number].split(' ')[0])
            m = int(content[case_number].split(' ')[1])

            # Do computations here
            result = slides(b, m)

            output_file.write('Case #' + str(case_number) + ": " + result + '\n')


def slides(b, m):
    if pow(2, b - 2) < m:
        return "IMPOSSIBLE"

    res = "POSSIBLE\n"
    mtx = numpy.zeros(shape=(b, b), dtype=numpy.int)

    for i in range(0, b - 1):
        for j in range(i + 1, b - 1):
            mtx[i][j] = 1

    if pow(2, b - 2) is m:
        for i in range(0, b - 1):
            mtx[i][-1] = 1
    else:
        i = 1
        while m > 0:
            mtx[i][-1] = m % 2
            m >>= 1
            i += 1

    for row in mtx[:-1]:
        for s in row:
            res += str(s)
        res += "\n"

    for s in mtx[-1]:
        res += str(s)

    return res


if __name__ == '__main__':
    main()
