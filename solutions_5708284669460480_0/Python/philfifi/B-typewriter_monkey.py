#!/usr/bin/python2

"""
  Google Code Jam 2015
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0

def overlap_size(target):
    for i in range(1, len(target)+1):
        if target[i:] == target[:-i]:
            return len(target) - i
    return 0

def max_bananas(keyboard, target, S, ov):

    if len(target) == S:
        return 1

    n = 1
    S -= len(target)

    n += S/ (len(target) - ov)

    return n

def proba_len_S(keyb_d, target, s, K, ov):
    num = 1
    den = 1


    # type the target

    i = 0
    ti = 0
    while i < s:
        num *= keyb_d[target[ti]]
        den *= K

        i += 1
        ti += 1
        if ti >= len(target):
            ti = ov

    return num, den

def next_state(K, keyboard, S, state):
    state[0] += 1

    for i in range(S):
        if state[i] >= K:
            state[i] = 0
            state[i+1] += 1

    return state

def nb_target(s, target):
    i = 0
    nb = 0
    total_index = 0
    while total_index < len(s):
#        print "total indey", total_index
        i = s.find(target, total_index)
        if i >= 0:
            nb += 1
            total_index = i + 1
        else:
            break
    return nb

#nb_target("lalalal", "lal")
#nb_target("TTTTTK", "TT")


def solve_case(case_no, keyboard, target, S    ):
    print "-------------- New case", case_no
    print "keyboard", keyboard, "target", target, S
    K = len(keyboard)

    keyb_d = {}
    for c in keyboard:
        keyb_d[c] = keyb_d.get(c, 0) + 1



    for c in target:
        if c not in keyboard:
            return 0

    ov = overlap_size(target)
    print "overlap size", ov

    m = max_bananas(keyboard, target, S, ov)
    print "max banana", m

#    print "proba", proba_len_S(keyb_d, target, S, K, ov)


    state = [0] * S
    nb_typed = 0
    total_cases = K**S
    while True:
#        print state

        s = ""
        for i in range(S):
            s += keyboard[state[i]]
#        print s

        t = nb_target(s, target)
#        print "typed", t
        nb_typed += t

        try:
            state = next_state(K, keyboard, S, state)
        except IndexError:
            break

    print "total_cases", total_cases
    print "nb_typed", nb_typed

    given_banana = 1. * nb_typed / total_cases

    return m - given_banana


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):

        K, L, S = [int(item) for item in fd.readline().split()]
        keyboard = fd.readline().strip()
        target =  fd.readline().strip()


        # Have read all stuff for this case:
        s = solve_case(case_no, keyboard, target, S)
        print "result", s
        f_out.write( "Case #%d: %.7f\n" % (case_no,
                                         s
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
