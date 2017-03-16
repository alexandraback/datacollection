#!/usr/bin/env python

from collections import defaultdict
import itertools

DEBUG = False

T = int(raw_input().strip())

def solve(L):
    first_words = defaultdict(int)
    second_words = defaultdict(int)
    for pairs in L:
        first_words[pairs[0]] += 1
        second_words[pairs[1]] += 1

    could_be_faked = 0
    new_first_words = defaultdict(int)
    new_second_words = defaultdict(int)
    possible_fakes1 = []
    for pair in L:
        if first_words[pair[0]] > 1 and second_words[pair[1]] > 1:
            possible_fakes1.append(pair)
        else:
            new_first_words[pair[0]] += 1
            new_second_words[pair[1]] += 1
            if DEBUG:
                print '1', pair, could_be_faked
    possible_fakes2 = []
    if DEBUG:
        print 'XX', new_first_words,
    for pair in possible_fakes1:
        if new_first_words[pair[0]] and new_second_words[pair[1]]:
            could_be_faked += 1
            if DEBUG:
                print '2', pair, could_be_faked
        elif new_first_words[pair[0]] or new_second_words[pair[1]]:
            possible_fakes2.append(pair)
        else:
            new_first_words[pair[0]] += 1
            new_second_words[pair[1]] += 1
            if DEBUG:
                print '3', pair, could_be_faked
    for pair in possible_fakes2:
        if new_first_words[pair[0]] and new_second_words[pair[1]]:
            could_be_faked += 1
            if DEBUG:
                print '4', pair, could_be_faked
        else:
            new_first_words[pair[0]] += 1
            new_second_words[pair[1]] += 1
            if DEBUG:
                print '5', pair, could_be_faked
    return could_be_faked


def count_fakes(L):
    first_words = set()
    second_words = set()
    fakes = 0
    for pair in L:
        if pair[0] in first_words and pair[1] in second_words:
            fakes += 1
        else:
            first_words.add(pair[0])
            second_words.add(pair[1])
    return fakes


def solve_slow(L, debug=None):
    if debug is not None:
        for new_l in itertools.permutations(L):
            if count_fakes(new_l) == debug:
                print new_l
                raise
    return max(count_fakes(new_l) for new_l in itertools.permutations(L))


for i in range(1, T+1):
    print ("Case #%d:" % i),
    N = int(raw_input().strip())
    L = []
    for j in range(1, N+1):
        words = raw_input().strip().split()
        L.append(words)
    if DEBUG and N < 10:
        X = solve(L)
        Y = solve_slow(L)
        print X, Y
        if X != Y:
            solve_slow(L, Y)
    else:
        print solve(L)
