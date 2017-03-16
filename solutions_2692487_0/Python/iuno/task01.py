import sys
import itertools
import collections
import functools
from math import *


def solve(size, motes):
    if size == 1:
        return len(motes)

    changes = []
    for i in range(len(motes)):
        inserts, size = required(size, motes[i])
        if inserts != 0:
            changes.append((i, inserts))

    num_deletes = 0
    num_inserts = 0
    for i in range(len(changes)-1, -1, -1):
        num_inserts += changes[i][1]
        if num_inserts > len(motes) - changes[i][0]:
            num_deletes += len(motes) - changes[i][0]
            motes[:changes[i][0]]
            changes = changes[:i]
            num_inserts = 0

    return num_inserts + num_deletes


def required(_from, _to):
    i = 0
    while _from <= _to:
        _from = 2 * _from - 1
        i += 1
    return i, _from + _to


def read_input(path):
    Chest = collections.namedtuple('Chest', ['id', 'required', 'content'])

    with open(path) as f:
        lineiterator = iter(f)

        num_tests = int(next(lineiterator))

        for i in range(num_tests):
            size, num_motes = list(map(int, next(lineiterator).split()))
            motes = sorted(list(map(int, next(lineiterator).split())))
            yield size, motes


def write_solutions(path, solutions):
    with open(path, "w") as f:
        for i, solution in zip(itertools.count(1), solutions):
            print("Case #{num}: {value:d}".format(num=i, value=solution), flush=True)
            print("Case #{num}: {value:d}".format(num=i, value=solution), file=f)


if __name__ == '__main__':
    todo = read_input(sys.argv[1])
    result = (solve(size, motes) for size, motes in todo)
    write_solutions(sys.argv[2], result)

