#!/usr/bin/env python
from __future__ import unicode_literals
import codecs
import fractions
import sys


def get_result(frac):
    if bin(frac.denominator).count('1') != 1:
        return 'impossible'

    result = 0
    while frac < 1:
        frac *= 2
        result += 1
    return result


def main(argv=sys.argv):
    assert len(argv) == 3, "argv was not of length 3: {}".format(argv)
    infile = argv[1]
    outfile = argv[2]
    with codecs.open(infile, 'r', 'utf8') as fin,\
            codecs.open(outfile, 'w', 'utf8') as fout:
        T = int(fin.readline().strip())
        for case_num in xrange(1, T+1):
            frac = fractions.Fraction(fin.readline().strip())
            result = get_result(frac)
            fout.write('Case #{}: {}\n'.format(case_num, result))
    return 0

if __name__ == "__main__":
    status = main()
    sys.exit(status)
