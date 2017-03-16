#!/usr/bin/env python

import sys
import scipy.stats

def do_testcase():
    N, X, Y = [int(s) for s in sys.stdin.readline().split(' ')]
    y_hat = Y
    x_hat = (abs(X) + Y) / 2
    N_smaller = (2 * x_hat - 1) * x_hat
    N_larger = (2 * x_hat + 1) * (x_hat + 1)
    if N_larger - 1 < N:
        return 1.0
    if N_smaller + y_hat >= N:
        return 0.0
    if N - N_smaller > 2 * x_hat:
        if N - N_smaller - 2 * x_hat > y_hat:
            return 1.0
    if 2 * x_hat <= y_hat:
        if N < N_larger:
            return 0.0
        else:
            return 1.0
    return 1 - scipy.stats.binom.cdf(y_hat, N - N_smaller, 0.5)

if __name__ == '__main__':
    T = int(sys.stdin.readline())
    for i in xrange(T):
        print 'Case #%i: %0.8f' % (i + 1, do_testcase())
