"""
NINE

Z - zero
W - TWO
X - SIX
G - EIGHT
T - THREE
R - FOUR
O - ONE
F - FIVE
S - SEVEN
"""

from collections import defaultdict


def reduce_by(counts, string, amount):
    for c in string:
        counts[c] -= amount


def answer(ss):
    counts = defaultdict(int)
    for c in ss:
        counts[c] += 1
    results = defaultdict(int)
    determinators = [
        [0, 'Z', 'ZERO'],
        [2, 'W', 'TWO'],
        [6, 'X', 'SIX'],
        [8, 'G', 'EIGHT'],
        [3, 'T', 'THREE'],
        [4, 'R', 'FOUR'],
        [1, 'O', 'ONE'],
        [5, 'F', 'FIVE'],
        [7, 'S', 'SEVEN'],
        [9, 'E', 'NINE'],
    ]
    for digit, det, letters in determinators:
        res = counts[det]
        for c in letters:
            counts[c] -= res
        results[digit] = res

    final = ""
    for x in xrange(0, 10):
        cc = str(x) * results[x]
        final += cc
    return final

cases = int(raw_input())

for ctr in xrange(cases):
    ss = raw_input()
    ans = answer(ss)
    print "Case #%d: %s" % (ctr + 1, ans)
