#!/usr/bin/env python
# coding: utf-8

import sys
from operator import itemgetter

def minTimes(N, R):
    A = sorted([(i, R[i][0]) for i in range(N)], key=itemgetter(1, 0));
    B = sorted([(i, R[i][1]) for i in range(N)], key=itemgetter(1, 0));
    FA = [0 for i in range(N)];
    FB = [0 for i in range(N)];
    score = 0;
    i = 0;
    j = 0;
    while True:
        while (i < N) and (score >= B[i][1]):
            score += 2 - FA[B[i][0]];
            FB[B[i][0]] = 1;
            i += 1;
        if i == N:
            return "%d" % (i+j);
        while (j < N) and (score >= A[j][1]) and score < B[i][1]:
            if (0 == FB[A[j][0]]):
                score += 1;
                FA[A[j][0]] = 1;
            j += 1;
        if score < B[i][1]:
            return "Too Bad";


with open(sys.argv[1]) as infile:
    inlines = [line.strip() for line in infile];
    T = int(inlines[0]);
    rowid = 1;
    for i in range(T):
        N = int(inlines[rowid]);
        rowid += 1;
        R = [[int(line.split()[0]), int(line.split()[1])] for line in inlines[rowid:rowid+N]];
        rowid += N;
        print "Case #%d: %s" % (i+1, minTimes(N, R));
