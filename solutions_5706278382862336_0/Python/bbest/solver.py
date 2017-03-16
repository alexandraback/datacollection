import sys
import fractions
from math import log

DEBUG = True


def solver(p, q):
    total_ancestors = 2 ** 40
    frac = fractions.Fraction(p, q)
    if total_ancestors % frac.denominator:
        return "impossible"
    mult = total_ancestors / frac.denominator
    total_elf_ancestors = mult * frac.numerator
    return int(log(total_ancestors, 2)) - int(log(total_elf_ancestors, 2))


def ssi(s, func=int):
    """
    space separated integers
    """
    return map(func, s.strip('\n').split())


def rl():
    return sys.stdin.readline()


def debug(*args):
    if args[-1] is not False and DEBUG:
        msg = " ".join([str(m) for m in args])
        sys.stderr.write(msg + '\n')


def main():
    # open input file
    # input_file = open('infile.txt')

    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        debug('Case #%d' % (c + 1))
        p, q = map(int, rl().split("/"))
        answer = solver(p, q)
        output.append('Case #%d: %s\n' % (c + 1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()


if __name__ == '__main__':
    main()
