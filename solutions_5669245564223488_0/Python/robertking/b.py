__author__ = "google.com/+RobertKing"
from sys import stdin
from itertools import permutations
from collections import Counter
import networkx as nx
from math import factorial

data = (line for line in stdin.read().splitlines())
#
# data = '''3
# 3
# ab bbbc cd
# 4
# aa aa bc c
# 2
# abc bcd'''.splitlines()
# data = iter(data)

cases = int(next(data))

def valid(subtrain):
    cntr = Counter(subtrain)
    mins = {}
    maxs = {}
    i = 0
    for c in subtrain:
        i += 1
        if c in mins:
            maxs[c] = i
        else:
            mins[c] = i
            maxs[c] = i
    return all(maxs[c] - mins[c] + 1 == cnt for c, cnt in cntr.iteritems())

for case in range(1, cases + 1):
    N = int(next(data))
    trains = next(data).split()
    possible = all(map(valid, trains))
    taken_by = {}
    if possible:
        for i, train in enumerate(trains):
            for c in train:
                if c in taken_by:
                        if taken_by[c] != i:
                            possible = False
                if c not in (train[0], train[-1]):
                    if c in taken_by:
                        if taken_by[c] != i:
                            possible = False
                    taken_by[c] = i

    starts_count = Counter()
    ends_count = Counter()
    both_count = Counter()
    if possible:
        for train in trains:
            s, e = train[0], train[-1]
            if s != e:
                starts_count[s] += 1
                ends_count[e] += 1
            else:
                both_count[s] += 1

    if max([1] + starts_count.values()) > 1 or max([1] + ends_count.values()) > 1:
        possible = False

    if possible:
        connections = set()
        front_breaks = set()
        end_breaks = set()
        for s in starts_count:
            if ends_count[s] > 0:
                #must go together..
                connections.add(s)
            else:
                front_breaks.add(s)
        for e in ends_count:
            if starts_count[e] > 0:
                #must go together..
                connections.add(s)
            else:
                end_breaks.add(s)
        # print both_count.values()
        # print len(front_breaks)
        nums = map(factorial, both_count.values())
        extra = 0 if len(connections) + 1 == len(trains) else 1
        nums.append(factorial(len(front_breaks) + extra))
        ans = 1
        for num in nums:
            ans = (ans * num) % 1000000007

    else:
        ans = 0





    #ans = ans % (1000000007)
    print "Case #%d: %s" % (case, ans)