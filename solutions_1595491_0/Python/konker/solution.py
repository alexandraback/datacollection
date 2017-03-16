#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author: Konrad Markus <konker@gmail.com>
#

import sys
import itertools

POS_VOTES = None

def main():
    prepare()

    T = int(sys.stdin.readline().rstrip())

    t = 1
    while (t <= T):
        dat = map(int, sys.stdin.readline().rstrip().split(" "))
        N = dat[0] # number of scores
        S = dat[1] # number of 'suprising' scores
        p = dat[2] # best score
        scores = dat[3:]

        solve(t, N, S, p, scores)
        t = t + 1


def prepare():
    global POS_VOTES
    POS_VOTES = list(itertools.combinations(3 * [0,1,2,3,4,5,6,7,8,9,10], 3))


def solve(t, N, S, p, scores):
    sys.stdout.write("Case #")
    sys.stdout.write(str(t))
    sys.stdout.write(": ")

    pos_regular = []
    pos_suprising = []
    chosen = []

    # get the possible votes for each googler
    for s in scores:
        vs_r = []
        vs_s = []
        tmp = []

        for v in POS_VOTES:
            if sum(v) == s and is_legal(v) and not set(v) in tmp:
                if is_surprising(v):
                    vs_s.append(v)
                else:
                    vs_r.append(v)
                tmp.append(set(v))

        pos_regular.append(vs_r)
        pos_suprising.append(vs_s)
        chosen.append(None)

    # do a pass taking all scores which only have suprising
    for i in xrange(N):
        if not pos_regular[i]:
            chosen[i] = best(pos_suprising[i]) 
            S = S - 1

    if S > 0:
        # try and get the options where suprising is better than regular
        for i in xrange(N):
            if not chosen[i] and pos_suprising[i]:
                b_r = max(best(pos_regular[i]))
                b_s = max(best(pos_suprising[i]))
                if b_s > b_r and b_s >= p and b_r < p:
                    chosen[i] = best(pos_suprising[i])
                    S = S - 1
            if S == 0:
                break

    if S > 0:
        # try and get the options where suprising is good
        for i in xrange(N):
            if not chosen[i] and pos_suprising[i]:
                b_s = max(best(pos_suprising[i]))
                if b_s >= p:
                    chosen[i] = best(pos_suprising[i])
                    S = S - 1
            if S == 0:
                break

    if S > 0:
        # make up the quota of suprising
        for i in xrange(N):
            if not chosen[i] and pos_suprising[i]:
                chosen[i] = best(pos_suprising[i])
                S = S - 1
            if S == 0:
                break

    # get the rest regular
    for i in xrange(N):
        if not chosen[i]:
            chosen[i] = best(pos_regular[i])

    sys.stdout.write(str(count(chosen, p)))
    sys.stdout.write("\n")

def is_legal(p):
    return (abs(p[0] - p[1]) < 3) and (abs(p[1] - p[2]) < 3) and (abs(p[0] - p[2]) < 3)

def is_surprising(p):
    return (abs(p[0] - p[1]) == 2) or (abs(p[1] - p[2]) == 2) or (abs(p[0] - p[2]) == 2)

def count(chosen, p):
    ret = 0
    for c in chosen:
        if max(c) >= p:
            ret = ret + 1
    return ret

def best(pos_votes):
    ret = None
    so_far = -1
    for v in pos_votes:
        if (max(v) > so_far):
            ret = v
    return ret


if __name__ == '__main__':
    main()

