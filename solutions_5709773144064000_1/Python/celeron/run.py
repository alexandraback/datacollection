#!/usr/bin/env python

with open('input') as fin:
    T = int(fin.readline())
    for i in xrange(T):
        C, F, X = [float(x) for x in fin.readline().split()]
        time = 0.0
        rate = 2.0
        min_time = X / 2.0
        while True:
            time += C / rate
            rate += F
            predicted_time = time + X / rate
            if predicted_time < min_time:
                min_time = predicted_time
            else:
                break
        print 'Case #%d: %.7f' % (i+1, min_time)

