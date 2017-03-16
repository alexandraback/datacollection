import sys
import argparse
from itertools import product
from operator import itemgetter


def read_scores(s):
    ret = []
    for x in s:
        try:
            ret.append(int(x))
        except ValueError:
            ret.append(None)
    return ret


def read_input(f):
    N = int(f.next())
    for i in xrange(N):
        c, j = f.next().strip().split()
        yield i, (read_scores(c), read_scores(j))


def solve(scores):
    N = len(scores[0])
    fmt = "%%0%dd" % N
    to_n = lambda digits: int("".join(map(str, digits)))
    t = []
    for s in scores:
        for i, x in enumerate(s):
            s[i] = xrange(10) if x is None else [x]
    for c, j in product(product(*scores[0]), product(*scores[1])):
        c, j = [to_n(_) for _ in c, j]
        t.append((abs(c - j), c, j))
    t.sort(key=itemgetter(2))
    t.sort(key=itemgetter(1))
    t.sort()
    return fmt % t[0][1], fmt % t[0][2]


def write_result(idx, scores, fo):
    c, j = scores
    fo.write("Case #%d: %s %s\n" % (idx + 1, c, j))


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
    for i, scores in read_input(args.in_):
        write_result(i, solve(scores), args.out)


if __name__ == "__main__":
    main(sys.argv)
