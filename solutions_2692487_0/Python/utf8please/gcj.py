#!/usr/bin/env python3

import os
import sys
import importlib
import time

def main():
    letter = sys.argv[1]
    dataset = sys.argv[2]
    attempt = '-' + sys.argv[3] if len(sys.argv) > 3 else ''

    solution = importlib.import_module("problem-{0}".format(letter))

    filename = '{0}-{1}{2}'.format(letter, dataset, attempt)
    with open(filename + '.in', 'r') as infile:
        with open(filename + '.out', 'w') as outfile:
            before = time.monotonic()
            t = int(infile.readline())
            for i in range(t):
                print("Case " + str(i))
                outfile.write('Case #{0}: '.format(i + 1))
                solution.solve(infile, outfile)
            delta = time.monotonic() - before
            print("All test cases finished in {0} ms.".format(delta * 1000))

if __name__ == '__main__':
    main()
