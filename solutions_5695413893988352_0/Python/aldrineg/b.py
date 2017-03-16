#!/usr/bin/python

import sys
import math

def get_file(argv):
    if len(argv) == 1:
        return "b.in"
    else:
        return "b_%s.in" % (argv[1])

def get_file_out(argv):
    if len(argv) == 1:
        return "b.out"
    else:
        return "b_%s.out" % (argv[1])

def print_answer(t, answer, f):
    answer = "Case #%d: %s" % (t, answer)
    print answer
    f.write(answer)
    f.write("\n")

def create_combinations(current):
    combinations = []
    for i in "0123456789":
        combinations.append(current + i)
    return combinations

def get_combinations(S):
    latest_round = ['']
    for i in xrange(0, len(S)):
        if S[i] == '?':
            new_round = []
            for s in latest_round:
                new_round = new_round + create_combinations(s)
        else:
            new_round = []
            for s in latest_round:
                new_round = new_round + [s+S[i]]
        latest_round = new_round
    return latest_round

def get_scores(C, J):
    c_set = get_combinations(C)
    j_set = get_combinations(J)
    scores = []
    for c in c_set:
        for j in j_set:
            c_raw = c.lstrip('0')
            j_raw = j.lstrip('0')
            if c_raw == '':
                c_raw = '0'
            if j_raw == '':
                j_raw = '0'
            c_score = int(c_raw)
            j_score = int(j_raw)
            scores.append((math.fabs(c_score - j_score), c_score, j_score))
    scores.sort()
    return scores[0]

def main(argv):
    f = open(get_file(argv), 'r')
    f_out = open(get_file_out(argv), 'w')
    T = int(f.readline())
    for t in xrange(1, T+1):
        L = f.readline().strip()
        parts = L.split(' ')
        C = parts[0]
        J = parts[1]
        scores = get_scores(C, J)
        print_answer(t, "{} {}".format(str(scores[1]).zfill(len(C)), str(scores[2]).zfill(len(J))), f_out)


if __name__ == "__main__":
    main(sys.argv)
