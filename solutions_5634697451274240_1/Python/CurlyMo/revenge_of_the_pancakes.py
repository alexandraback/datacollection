#!/usr/bin/env python
import argparse


def flip(S, i):
    for c in range(i):
        if S[c] == '+':
            S[c] = '-'
        else:
            S[c] = '+'
    return S


def main(infile, outfile):
    with open(infile, 'r') as input, open(outfile, 'w') as out:
        num_cases = int(input.readline())
        for case in range(1, num_cases+1):
            out.write('Case #{}: '.format(case))

            S = list(input.readline().rstrip())
            flips = 0
            while True:
                if all(p == '+' for p in S):
                    break
                i = ''.join(S).rfind('-') + 1
                S = flip(S, i)
                flips += 1

            out.write(str(flips) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="codejam qual A")
    parser.add_argument('-i', '--input', type=str,
                        help='Input file')
    parser.add_argument('-o', '--output', type=str,
                        help='Output file')
    args = parser.parse_args()
    main(args.input, args.output)
