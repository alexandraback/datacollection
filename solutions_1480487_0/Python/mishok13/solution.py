#!/usr/bin/env python


import argparse
import sys
from math import fsum


def solve(contestants, scores):
    overall = fsum(scores)
    for score in scores:
        if score != 0:
            yield score, 100 * max(0, ((2. / contestants) - (float(score) / overall)))




def main(args):
    tests = next(args.input).strip()
    for index, line in enumerate(args.input, 1):
        line = map(int, line.strip().split())
        contestants, scores = line[0], line[1:]
        zeros = scores.count(0)
        results = dict(solve(float(contestants), scores))
        overall = sum(results.values())
        if zeros:
            results = [results.get(score, (100.0 - overall) / zeros) for score in scores]
        else:
            results = [results[score] for score in scores]
        print("Case #{}: {}".format(index, " ".join(map("{:f}".format, results))))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input', type=argparse.FileType('r'), default=sys.stdin)
    main(parser.parse_args())
