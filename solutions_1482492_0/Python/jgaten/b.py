#!/usr/bin/env python
from __future__ import division
import sys
from math import sqrt

def dx(dt, v0, a):
    """distance travelled"""
    return v0 * dt + 0.5 * a * dt ** 2

def quadratic(a, b, c):
    t1 = (-b + sqrt(b**2 - 4 * a * c)) / (2 * a)
    t2 = (-b + sqrt(b**2 - 4 * a * c)) / (2 * a)
    return t1, t2

def solve(D, N, A, othercar, accels):
    assert othercar[0][0] == 0
    times = []
    if len(othercar) == 1:
        other_speed = 0
    else:
        other_speed = (othercar[1][1] - othercar[0][1]) / (othercar[1][0])
    other_start = othercar[0][1]
    for a in accels:
        catchup = quadratic(a/2, -other_speed, -other_start)
        catchup = min(catchup)
        time_to_bottom = sqrt(2 * D / a)
        if time_to_bottom > catchup:
            # going to catch up with the car, so slow down.
            # will arrive at the bottom when the other car does
            time_to_bottom = (D - other_start) / other_speed
        times.append(time_to_bottom)
    return times

if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            print "Case #{0}:".format(case)
            print >> fout, "Case #{0}:".format(case)

            D, N, A = map(float, fin.readline().split())
            N, A = int(N), int(A)
            othercar = [tuple(map(float, fin.readline().split())) for i in xrange(N)]
            accels = map(float, fin.readline().split())

            solns = solve(D, N, A, othercar, accels)
            for time in solns:
                print time
                print >> fout, time
