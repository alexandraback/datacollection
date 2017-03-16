from collections import defaultdict
from itertools import groupby
from math import factorial
from operator import mul


def count(cars):
    letters = set()
    edges = dict()
    repetitions = defaultdict(lambda: 0)
    for c in cars:
        letters.add(c[0])
        letters.add(c[-1])
        if c == len(c) * c[0]:
            repetitions[c[0]] += 1
        elif c[0] == c[-1]:
            return 0
    rep_fact = reduce(mul, map(factorial, repetitions.values()), 1)
    cars = [c for c in cars if c != len(c) * c[0]]
    for c in cars:
        for l in [l for l, _ in groupby(c)][1:-1]:
            if l in letters:
                return 0
            letters.add(l)
        repetitions.pop(c[0], None)
        repetitions.pop(c[-1], None)
        if c[0] in edges or c[-1] in edges.values() or (c[-1] in edges and edges[c[-1]] == c[0]):
            return 0
        edges[c[0]] = c[-1]
    parts = len(repetitions)
    while edges:
        _, e = edges.popitem()
        while e in edges:
            e = edges.pop(e)
        parts += 1
    return rep_fact * factorial(parts)


for t in range(input()):
    print "Case #%s:" % str(t + 1),
    n = input()
    cars = raw_input().split()
    print count(cars) % 1000000007
