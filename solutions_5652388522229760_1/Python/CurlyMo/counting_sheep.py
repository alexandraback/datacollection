#!/usr/bin/env python
import argparse

ALL_DIGITS = set(range(10))


def main(infile, outfile):
    with open(infile, 'r') as input, open(outfile, 'w') as out:
        num_cases = int(input.readline())
        for case in range(1, num_cases+1):
            out.write('Case #{}: '.format(case))

            N = int(input.readline().rstrip())
            insomnia = False
            seen_digits = set()
            i = 1
            while True:
                num = i * N
                digits = set(int(char) for char in str(num))
                seen_digits |= digits
                if seen_digits == ALL_DIGITS:
                    break
                if N == 0:
                    insomnia = True
                    break
                i += 1

            if insomnia:
                out.write('INSOMNIA\n')
            else:
                out.write(str(num) + '\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="codejam qual A")
    parser.add_argument('-i', '--input', type=str,
                        help='Input file')
    parser.add_argument('-o', '--output', type=str,
                        help='Output file')
    args = parser.parse_args()
    main(args.input, args.output)
