#!/usr/bin/env python2

M = [
    ("ZERO", "Z", 0),
    ("SIX", "X", 6),
    ("TWO", "W", 2),
    ("EIGHT", "G", 8),
    ("SEVEN", "S", 7),
    ("FIVE", "V", 5),
    ("NINE", "I", 9),
    ("FOUR", "F", 4),
    ("THREE", "H", 3),
    ("ONE", "O", 1)
]

def solve(S):
    digits = {}
    Sp = {}
    for c in S:
        if c in Sp:
            Sp[c] += 1
        else:
            Sp[c] = 1
    for m in M:
        if m[1] in Sp and Sp[m[1]] > 0:
            cnt = Sp[m[1]]
        else:
            continue
        digits[m[2]] = cnt
        for c in m[0]:
            Sp[c] -= cnt
            assert(Sp[c] >= 0)
    number = ""
    for d in sorted(digits.keys()):
        number += str(d) * digits[d]
    return number

T = int(raw_input())
for i in xrange(1, T+1):
    S = raw_input().strip()
    print "Case #%s: %s" % (i, solve(S))
