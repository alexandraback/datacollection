#!/usr/bin/env python

import itertools
import sys

def read(filename):
    """Yield a "test" chunk of lines from filename."""
    with open(filename, 'r') as f:
        num_tests = int(f.readline())
        for t in range(num_tests):
            yield f.readline()

def munge(lines):
    """
    Yield a test from raw line.

    Test data structure:
        * 2-tuple of ints: (start, end)

    """
    for line in lines:
        start, end = line.split()
        yield (int(start), int(end))

def is_palindrome(num):
    s = str(num)
    rev = s[::-1]
    return s == rev

def find_fair_and_square(start, end):
    results = []
    counter = 0
    i = 0
    while True:
        i += 1
        if is_palindrome(i):
            square = i ** 2
            if square > end:
                break
            if is_palindrome(square) and start <= square <= end:
                results.append(tuple([i, square]))
                counter += 1
    return results
    # return counter


def format(index, result):
    """Format output properly."""
    output = "Case #%s: %s" % (index, result)
    return output


def main(argv=None):
    if argv == None:
        argv = sys.argv

    if len(argv) != 2:
        sys.stderr.write("Usage: %s <input_file>" % argv[0])
        return 2

    infile = argv[1]
    raw = read(infile)
    munged = munge(raw)
    # print list(munged)

    fair_and_square = find_fair_and_square(0, 10**15)
    # for f in fair_and_square:
    #     print f

    for index, endpoints in enumerate(munged):
        counter = 0
        start = endpoints[0]
        end = endpoints[1]
        # print start, end
        for f in fair_and_square:
            if start <= f[1] <= end:
                counter += 1
        print format(index + 1, counter)


if __name__ == '__main__':
    sys.exit(main())
