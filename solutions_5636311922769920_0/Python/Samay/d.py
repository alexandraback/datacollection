#!/usr/bin/env python


DEBUG = False

import sys

def debug(*args):
    if DEBUG:
        print ' '.join(map(str, args))

def int_input():
    text = raw_input()
    return int(text)

def float_input():
    text = raw_input()
    return int(text)

def list_input(size=None):
    text = raw_input()
    str_values = text.split(' ')
    if size is not None:
        assert len(str_values) == size
    return str_values

def intlist_input(size=None):
    return map(int, list_input(size))

def floatlist_input(size=None):
    return map(float, list_input(size))

def loop(count, func):
    for x in xrange(0, count):
        func(x)

def print_case(idx, fmt, *args):
    prefix = 'Case #{}:'.format(idx + 1)
    if len(args):
        print prefix, fmt % args
    else:
        print prefix, fmt

class Plain(object):
    def __init__(self, size, init=None):
        self.size = size
        self.data = [init] * (self.size[0] * self.size[1])

    def __getitem__(self, coord):
        r, c = coord
        index = r * self.size[1] + c
        return self.data[index]

    def __setitem__(self, coord, item):
        r, c = coord
        index = r * self.size[1] + c
        self.data[index] = item

    def debug(self):
        debug('Plain {}x{}'.format(self.size[0], self.size[1]))
        for r in xrange(0, self.size[0]):
            row = [self[r, c] for c in xrange(0, self.size[1])]
            debug(row)


class Fractal(object):
    def __init__(self, sequence_size, complexity):
        self.sequence_size = sequence_size
        self.complexity = complexity

    @property
    def volume(self):
        return self.sequence_size ** self.complexity

    def factors_from_index(self, index):
        assert 0 <= index < self.volume
        factors = []
        for dim in range(0, self.complexity):
            m = index / (self.sequence_size ** dim)
            factors.append(m % self.sequence_size)
        assert len(factors) == self.complexity
        return factors

    def index_from_factors(self, factors):
        assert len(factors) == self.complexity
        index = 0
        for dim, factor in enumerate(factors):
            index += factor * (self.sequence_size ** dim)
        return index

    def search_indexset(self):
        factor_space = list(range(0, self.sequence_size))

        indexset = []
        while factor_space:
            factors = factor_space[:self.complexity]
            del factor_space[:self.complexity]
            if len(factors) < self.complexity:
                factors += [0] * self.complexity
                factors = factors[:self.complexity]
            index = self.index_from_factors(factors)
            indexset.append(index)
        indexset.sort()
        assert self.validate_indexset(indexset)
        return indexset

    def validate_indexset(self, indexset):
        factorss = [self.factors_from_index(i) for i in indexset]
        factors = reduce(lambda a, b: a + b, factorss, [])
        return set(range(0, self.sequence_size)) == set(factors)


def humanize(x):
    return map(lambda e: e + 1, x)


def machinize(x):
    return map(lambda e: e - 1, x)


def solution(idx):
    K, C, S = map(int, list_input())
    sequence_size = K
    complexity = C
    tester_count = S

    f = Fractal(sequence_size, complexity)
    indexset = humanize(f.search_indexset())
    if len(indexset) > tester_count:
        print_case(idx, 'IMPOSSIBLE')
    else:
        print_case(idx, ' '.join(map(str, indexset)))


if __name__ == '__main__':
    count = int_input()
    loop(count, solution)
