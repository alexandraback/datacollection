#!/usr/bin/python

import sys
from itertools import islice


def solve(n):
    p168 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]

    def find_divisor(x):
        for d in p168:
            if x % d == 0:
                return d
        return None

    for x2 in xrange(2**(n-2), 2**(n-1) - 1):
        x2_str = '{:b}1'.format(x2)
        divisors = [find_divisor(int(x2_str, b)) for b in range(2, 11)]
#        print " ->", x2_str, divisors
        if all(divisors):
            yield x2_str, divisors


def main():
    T = int(next(sys.stdin))
    for i in xrange(1, T+1):
        N, J = map(int, next(sys.stdin).split())
        print "Case #{}:".format(i)
        for x, ds in islice(solve(N), J):
            print x, " ".join(str(d) for d in ds)


if __name__ == '__main__':
    main()

