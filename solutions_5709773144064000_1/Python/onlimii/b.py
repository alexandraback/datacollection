#!/usr/bin/env python

with open("B-large.in", "r") as fin:
    N = int(fin.readline())
    fout = open("B-large.out", "w")

    for i in xrange(N):
        C, F, X = map(float, fin.readline().split())
        time_stamp = 0
        time = 0
        to_wait = X / 2
        to_buy = C / 2 + X / (F + 2)
        while to_wait > to_buy:
            time += C / (time_stamp * F + 2)
            time_stamp += 1
            to_wait = X / (time_stamp * F + 2)
            to_buy = C / (time_stamp * F + 2) + X / ((time_stamp+1) * F + 2)
        time += to_wait
        fout.write("Case #%d: %.7f\n" % (i+1, time))

