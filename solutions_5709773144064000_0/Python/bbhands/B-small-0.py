#!/usr/bin/python
# -*- coding: utf-8 -*-

if __name__ == "__main__":

    fin = open("B-small-0.in", "r")
    fout = open("B-small-0.out", "w")
    T = int(fin.readline())

    for t in xrange(0, T):
        params = map(float, fin.readline().strip().split(' '))
        C = params[0]
        F = params[1]
        X = params[2]

        total_secs = 0.0
        rate = 2.0
        while True:
            if X/rate < C/rate + X/(rate+F):
                total_secs += X/rate
                break
            else:
                total_secs += C/rate
                rate += F
    
        answer = "%.7f" % total_secs

        fout.write("Case #%i: %s\n" % (t+1, answer))
    
    fin.close()
    fout.close()

