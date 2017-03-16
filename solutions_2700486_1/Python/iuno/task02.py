import sys
import itertools
import collections
import functools


# from stackoverflow:http://stackoverflow.com/questions/3056179/binomial-test-in-python-for-very-large-numbers
from math import *


def normal_pdf(x, m, v):
    return 1.0/sqrt(2*pi*v) * exp(-(x-m)**2/(2*v))


def binomial_pdf(p, n, k):
    if n < 100:
        return nchoosek(n, k) * p**k * p**(n-k)  # Fall back to your current method
    return normal_pdf(k, n*p, n*p*(1.0-p))


####
def solve(diamonds, x, y):
    n = abs(x) + y
    smaller_pyramid = ((n-1)**2 - n + 1) // 2 + (n - 1)
    if diamonds < smaller_pyramid:
        return 0.0
    diamonds -= smaller_pyramid

    if x == 0:
        return 1.0 if diamonds - 2 * n >= 1 else 0.0

    if diamonds > y + n:
        return 1.0
    return sum(binomial_pdf(0.5, diamonds, k) for k in range(y+1, diamonds+1))


def nchoosek(n, k):
    return fac(n)/(fac(n-k)*fac(k))


def fac(n):
    return 1 if n == 0 else n * fac(n-1)


def read_input(path):
    Chest = collections.namedtuple('Chest', ['id', 'required', 'content'])

    with open(path) as f:
        lineiterator = iter(f)

        num_tests = int(next(lineiterator))

        for i in range(num_tests):
            diamonds, x, y = list(map(int, next(lineiterator).split()))
            yield diamonds, x, y


def write_solutions(path, solutions):
    with open(path, "w") as f:
        for i, solution in zip(itertools.count(1), solutions):
            print("Case #{num}: {value:.10f}".format(num=i, value=solution), flush=True)
            print("Case #{num}: {value:.10f}".format(num=i, value=solution), file=f)


if __name__ == '__main__':
    todo = read_input(sys.argv[1])
    result = (solve(d, x, y) for d, x, y in todo)
    write_solutions(sys.argv[2], result)

