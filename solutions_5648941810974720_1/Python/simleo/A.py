import sys
import argparse
from collections import Counter

DIGITS = ["ZERO", "ONE", "TWO", "THREE", "FOUR",
          "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]


def read_input(f):
    N = int(f.next())
    for i in xrange(N):
        yield i, f.next().strip()


def solve(case):
    number = []
    counts = Counter(case)
    while 'G' in counts:
        number.append('8')
        counts -= Counter("EIGHT")
    while 'U' in counts:
        number.append('4')
        counts -= Counter("FOUR")
    while 'Z' in counts:
        number.append('0')
        counts -= Counter("ZERO")
    while 'W' in counts:
        number.append('2')
        counts -= Counter("TWO")
    while 'F' in counts:
        number.append('5')
        counts -= Counter("FIVE")
    while 'H' in counts:
        number.append('3')
        counts -= Counter("THREE")
    while 'V' in counts:
        number.append('7')
        counts -= Counter("SEVEN")
    while 'X' in counts:
        number.append('6')
        counts -= Counter("SIX")
    while 'O' in counts:
        number.append('1')
        counts -= Counter("ONE")
    while 'N' in counts:
        number.append('9')
        counts -= Counter("NINE")
    while 'I' in counts:
        number.append('5')
        counts -= Counter("FIVE")
    if set("".join(DIGITS[int(_)] for _ in number)) != set(case):
        raise RuntimeError("ERROR: case: %s, n: %s" % (case, number))
    return "".join(sorted(number))


def write_result(idx, res, fo):
    fo.write("Case #%d: %s\n" % (idx + 1, res))


def make_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", '--in_', metavar="FILE", help="input file")
    parser.add_argument("-o", "--out", metavar="FILE", help="output file")
    return parser


def main(argv):
    parser = make_parser()
    args = parser.parse_args(argv[1:])
    if args.in_ is None:
        args.in_ = sys.stdin
    else:
        args.in_ = open(args.in_)
    if args.out is None:
        args.out = sys.stdout
    else:
        args.out = open(args.out)
    for i, case in read_input(args.in_):
        write_result(i, solve(case), args.out)


if __name__ == "__main__":
    main(sys.argv)
