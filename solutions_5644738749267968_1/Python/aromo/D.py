#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
import numpy as np

sys.setrecursionlimit(10000)

def input_words():
    line = IN.readline()
    return line.strip().split()

def input_ints():
    return map(int, input_words())

def input_floats():
    return map(float, input_words())

def format_sequence(s, formatter='%s'):
    return " ".join(map(lambda x: formatter % (x,), s))


def plain_wins_from_scores(scores):
    plain_hurdle = 1 + np.arange(len(scores))[::-1]
    return max(plain_hurdle - scores)

def plain_wins(naomi, ken):
    scores = []
    for n in naomi:
        scores.append((n < ken).sum())
    scores = np.array(scores)
    
    return  plain_wins_from_scores(scores)

def cheat_wins(naomi, ken):
    if len(naomi) == 0:
        return 0

#    print 'try', naomi, ken

    if naomi[0] < ken[0]:
#        print 'take a loss'
        return cheat_wins(naomi[1:], ken[:-1])
    else:
#        print 'take a win'
        return 1 + cheat_wins(naomi[1:], ken[1:])


def solve_one():
    N = input_ints()[0]
    naomi = np.array(sorted(input_floats()))
    ken = np.array(sorted(input_floats()))
    return '%d %s' % (cheat_wins(naomi, ken), plain_wins(naomi, ken))


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()

# _ = plain_wins_from_scores(np.array([5, 5, 4, 1, 0]))

# _ = plain_wins_from_scores(np.array([5, 5, 3, 1, 0]))
