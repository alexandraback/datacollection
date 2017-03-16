import sys
import itertools
import math
import collections

def area(r, i):
    return 2*i*i + 2*r*i - i

def test(r, i, t):
    return area(r, i) <= t

def find_num_circles(r, t):
    a = 1
    while test(r, 2*a, t):
        a*=2
    b = 2*a
    while a+1<b:
        half = math.ceil((a+b)/2.0)
        if test(r, half, t):
            a = half
        else:
            b = half
    return a


def read_input(path):
    Chest = collections.namedtuple('Chest', ['id', 'required', 'content'])

    with open(path) as f:
        lineiterator = iter(f)

        num_tests = int(next(lineiterator))

        for i in range(num_tests):

            spec = list(map(int, next(lineiterator).split()))
            yield spec[0], spec[1]


def write_solutions(path, solutions):
    with open(path, "w") as f:
        for i, solution in zip(itertools.count(1), solutions):
            print("Case #{num}: {value}".format(num=i, value=str(solution)), flush=True)
            print("Case #{num}: {value}".format(num=i, value=str(solution)), file=f)


if __name__ == '__main__':
    todo = read_input(sys.argv[1])
    result = (find_num_circles(r,t) for r,t in todo)
    write_solutions(sys.argv[2], result)

