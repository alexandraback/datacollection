#!/usr/bin/env python
import argparse
import itertools


def is_prime(n):
    if n == 2 or n == 3:
        return (True, None)
    if n < 2 or n % 2 == 0:
        return (False, 2)
    if n < 9:
        return (True, None)
    if n % 3 == 0:
        return (False, 3)
    r = int(n**0.5)
    f = 5
    while f <= r:
        if n % f == 0:
            return (False, f)
        if n % (f+2) == 0:
            return (False, f+2)
        f += 6
    return (True, None)


def main(infile, outfile):
    with open(infile, 'r') as input, open(outfile, 'w') as out:
        num_cases = int(input.readline())
        for case in range(1, num_cases+1):
            out.write('Case #{}:\n'.format(case))

            N, J = (int(x) for x in input.readline().rstrip().split())
            perms = itertools.product(['0', '1'], repeat=N-2)
            for i in range(J):
                print(i)
                for perm in perms:
                    perm = ('1',) + perm + ('1',)
                    is_coinjam = True
                    divisors = []
                    coin = ''.join(perm)
                    for base in range(2, 11):
                        prime, divisor = is_prime(int(coin, base))
                        if prime:
                            is_coinjam = False
                            break
                        divisors.append(str(divisor))

                    if is_coinjam:
                        out.write(' '.join([coin] + divisors))
                        out.write('\n')
                        break


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="codejam qual A")
    parser.add_argument('-i', '--input', type=str,
                        help='Input file')
    parser.add_argument('-o', '--output', type=str,
                        help='Output file')
    args = parser.parse_args()
    main(args.input, args.output)
