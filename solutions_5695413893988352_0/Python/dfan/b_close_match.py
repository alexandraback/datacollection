#!/usr/bin/python
#flake8: noqa

import sys
from copy import copy

def assume_0(score):
    ret = copy(score)
    for i in xrange(len(ret)):
        if ret[i] == '?':
            ret[i] = '0'
    return ret

def assume_9(score):
    ret = copy(score)
    for i in xrange(len(ret)):
        if ret[i] == '?':
            ret[i] = '9'
    return ret

def diff(coder, jammer):
    c = int("".join(coder))
    j = int("".join(jammer))
    return c - j

def assume(score, index, digit):
    assert(score[index] == '?')
    ret = copy(score)
    ret[index] = str(digit)
    return ret

def less_than(coder, jammer, length):
    for i in xrange(length):
        if coder[i] < jammer[i]:
            return True
        if coder[i] > jammer[i]:
            return False
    return False

def equal(a, b):
    return a[0] == b[0] and a[1] == b[1] and a[2] == b[2]

def best_choice_2(a, b):
    if abs(a[0]) < abs(b[0]):
        return a
    if abs(a[0]) > abs(b[0]):
        return b
    if less_than(a[1], b[1], len(a[1])):
        return a
    if less_than(b[1], a[1], len(a[1])):
        return b
    if less_than(a[2], b[2], len(a[2])):
        return a
    if less_than(b[2], a[2], len(a[2])):
        return b
    sys.stderr.write('Unhandled case. Defaulting to 1\n' + str(a) + '\n' + str(b) + '\n')
    return a

def best_choice(choice_1, choice_2, choice_3):

    if equal(choice_1, choice_2):
        return best_choice_2(choice_1, choice_3)
    if equal(choice_2, choice_3):
        return best_choice_2(choice_1, choice_2)
    if equal(choice_1, choice_3):
        return best_choice_2(choice_1, choice_2)

    if abs(choice_2[0]) < abs(choice_1[0]) and abs(choice_2[0]) < abs(choice_3[0]):
        return choice_2
    if abs(choice_1[0]) < abs(choice_2[0]) and abs(choice_1[0]) < abs(choice_3[0]):
        return choice_1
    if abs(choice_3[0]) < abs(choice_1[0]) and abs(choice_3[0]) < abs(choice_2[0]):
        return choice_3

    if abs(choice_1[0]) < abs(choice_3[0]) and abs(choice_2[0]) < abs(choice_3[0]):
        return best_choice_2(choice_1, choice_2)
    if abs(choice_1[0]) < abs(choice_2[0]) and abs(choice_3[0]) < abs(choice_2[0]):
        return best_choice_2(choice_1, choice_3)
    if abs(choice_2[0]) < abs(choice_1[0]) and abs(choice_3[0]) < abs(choice_1[0]):
        return best_choice_2(choice_2, choice_3)

    sys.stderr.write('Unhandled case. Defaulting to 1\n' + str(choice_1) + '\n' + str(choice_2) + '\n' + str(choice_3) + '\n')
    return choice_1

def min_diff(coder, jammer, i):
    if i == len(coder):
        return diff(coder, jammer), coder, jammer
    # If there is a large disparity already, then assume 0 or assume 9 to minimize it
    if less_than(coder, jammer, i):
        # coder < jammer, assume all ?=9 for coder, ?=0 for jammer
        c = assume_9(coder)
        j = assume_0(jammer)
        return diff(c, j), c, j
    if less_than(jammer, coder, i):
        # coder > jammer, assume all ?=0 for coder, ?=9 for jammer
        c = assume_0(coder)
        j = assume_9(jammer)
        return diff(c, j), c, j
    if coder[i] == '?' and jammer[i] == '?':
        # Ambiguous, set one of them to 0
        choice_1 = min_diff(assume(coder, i, 0), jammer, i)
        choice_2 = min_diff(coder, assume(jammer, i, 0), i)
        # Minimize coders first
        if abs(choice_1[0]) <= abs(choice_2[0]):
            return choice_1
        return choice_2
    if coder[i] == '?':
        # Assume the same
        choice_1 = min_diff(assume(coder, i, jammer[i]), jammer, i + 1)
        # Assume coder less by 1
        digit = max(int(jammer[i]) - 1, 0)
        choice_2 = min_diff(assume(coder, i, digit), jammer, i + 1)
        # Assume coder greater by 1
        digit = min(int(jammer[i]) + 1, 9)
        choice_3 = min_diff(assume(coder, i, digit), jammer, i + 1)
        return best_choice(choice_1, choice_2, choice_3)
    if jammer[i] == '?':
        # Assume the same
        choice_1 = min_diff(coder, assume(jammer, i, coder[i]), i + 1)
        # Assume coder less by 1
        digit = max(int(coder[i]) - 1, 0)
        choice_2 = min_diff(coder, assume(jammer, i, digit), i + 1)
        # Assume coder greater by 1
        digit = min(int(coder[i]) + 1, 9)
        choice_3 = min_diff(coder, assume(jammer, i, digit), i + 1)
        return best_choice(choice_1, choice_2, choice_3)
    return min_diff(coder, jammer, i + 1)

def solve(coder, jammer, i):
    """Main solution"""
    diff, c, j = min_diff(list(coder), list(jammer), 0)
    # print diff, c, j
    return "".join(c) + " " + "".join(j)

def output_case(i, result):
    output = {
        "case": i + 1,
        "result": result
    }
    print "Case #%(case)s: %(result)s" % output

# Default to "A-large.in" if no command line args
filename = "A-large.in"
if len(sys.argv) >= 2:
    filename = sys.argv[1]
with open(filename) as input_file:
    # Number of tests
    T = int(input_file.readline())
    for i in xrange(T):
        # pancake stack
        S = input_file.readline().strip()
        coder, jammer = S.split()
        result = solve(coder, jammer, i)
        output_case(i, result)
