#!/usr/bin/env python

import collections
from fractions import Fraction as F
import sys
import itertools

def generate(l, s, kw, nk, word, typed, prob):
    if len(typed) == s:
        return [(prob, typed)]
    else:
        r = []
        for k, w in kw.items():
            r.extend(generate(l, s, kw, nk, word, typed + [k], prob * F(w, nk)))
        return r


#print generate(3, 5, {'o': 1, 'k': 1}, 2, 'oko', [], F(1, 1))

def count_overlapping(needle, haystack):
    c = 0
    i = haystack.find(needle, 0)
    while i != -1:
        c += 1
        i = haystack.find(needle, i + 1)
    return c

#assert count_overlapping('oko', 'okoko') == 2


def solve(k, l, s, keyboard, word):
    if not (set(keyboard) - set(word)):
        return 0

    kw = collections.defaultdict(int)
    for key in keyboard:
        kw[key] += 1
    nk = len(keyboard)
    prob_words = generate(l, s, kw, nk, word, [], F(1, 1))
    prob_words = [(p, ''.join(w)) for p, w in prob_words]
    prob_words = [(p, w) for p, w in prob_words if word in w]
    expected = 0.0
    max_seen = 0
    for p, w in prob_words:
        count = count_overlapping(word, w)
        max_seen = max(max_seen, count)
        expected += count * p
    return max_seen - expected

solve(42, 3, 5, 'ok', 'oko')


infile = open(sys.argv[1])
t = int(infile.readline())

for x in xrange(t):
    sys.stderr.write(str(x) + "\n")
    k, l, s = [int(i) for i in infile.readline().strip().split()]
    keyboard = infile.readline().strip()
    word = infile.readline().strip()

    solution = solve(k, l, s, keyboard, word)
    print "Case #%d: %0.7f" % (x + 1, solution)
