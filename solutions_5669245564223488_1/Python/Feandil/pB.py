#!/usr/env/python

from itertools import permutations
from math import factorial
from sys import stdin


class BadOne(Exception):
    pass


def simplify(s, seen):
    first = s[0]
    last = s[0]
    pp = None
    for c in s:
        if c == last:
            continue
        if last == first:
            last = c
            first == None
            continue
        if last in seen:
            raise BadOne()
        seen.add(last)
        pp = last
        last = c
    if pp is not None and last == s[0]:
        raise BadOne()
    seen.add(last)
    return s[0] + s[-1]


def dict_append(dic, key, val):
    try:
        dic[key].append(val)
    except KeyError:
        dic[key] = [val]


def triage(train):
    double = {}
    starts = {}
    ends_seen = set()
    simplified_train = []
    for chain in train:
        if chain[0] == chain[1]:
            dict_append(double, chain[0], chain)
        else:
            if chain[1] in ends_seen:
                raise BadOne()
            ends_seen.add(chain[1])
            simplified_train.append(chain)
            dict_append(starts, chain[0], chain)
    for key in starts:
        if len(starts[key]) > 1:
            raise BadOne()
    return (simplified_train, starts, double)


def is_valid(s):
    seen = set()
    prev = None
    for c in s:
        if c == prev:
            continue
        if prev != None:
            seen.add(prev)
        if c in seen:
            return False
        prev = c
    return True

def solve_prob():
    l = int(stdin.readline().strip())
    raw = stdin.readline().strip()
    train = raw.split()
    seen = set()
    try:
        simple_train = [simplify(s, seen) for s in train]
        (simple_train, starts, double) = triage(simple_train)
    except BadOne:
        return 0
    mult = 1
    for d in double:
        mult *= factorial(len(double[d]))
    solved = []
    seen = set()
    while simple_train != []:
        cur = simple_train.pop()
        first = cur
        solved.append(cur)
        while True:
           if cur[0] in seen:
               return 0
           seen.add(cur[0])
           try:
               del double[cur[0]]
           except KeyError:
               pass
           try:
             next = starts[cur[-1]][0]
           except KeyError:
             break
           del[starts[cur[-1]]]
           try:
               simple_train.remove(next)
           except:
               solved.remove(next)
               break
           cur = next
        try:
           del double[cur[1]]
        except KeyError:
           pass
        if cur != first and first[0] == cur[-1]:
           return 0
    if len(solved) == 0:
        return mult * factorial(len(double))
    return factorial(len(solved) + len(double)) * mult

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, solve_prob()))
