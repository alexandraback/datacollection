#!/usr/bin/python
""" template.py input-file > output-file"""

import sys
from numpy import *

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


def real(C, F, X):
    goal_rate = F * (X - C) / C
#    print 'cost', C, 'rate_boost', F, 'goal', X, 'goal_rate', goal_rate

    t = 0
    rate = 2.

    # unaffordable factories
    if X < C:
        return X / rate

    # evaluate whenever we have no cookies
    while True:
        # should we buy more factories?
#        print 't', t, 'rate', rate
        if rate > goal_rate:
            time_to_goal = X / rate
            return t + time_to_goal

        else:
            t += C / rate
            rate += F
    

def solve_one():
    """ XXX the real code comes here """
    C, F, X = input_floats()
    return real(C, F, X)


if __name__ == "__main__":
    assert(len(sys.argv) == 2)
    IN = open(sys.argv[1])

    T = input_ints()[0]
    
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()
        sys.stderr.write("CASE #%d DONE\n" % (i+1,))
        sys.stderr.flush()

#print real(500., 4., 2000.)
