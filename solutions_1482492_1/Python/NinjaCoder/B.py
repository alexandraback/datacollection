#!/usr/bin/python

import sys
import math

def quadratic(a, b, c):
    return (-b + math.sqrt(math.pow(b, 2) - (4 * a * c))) / (2 * a)

def calc_dt(my_v, my_a, their_x, their_v):
    a = 0.5 * my_a
    b = my_v - their_v
    c = -their_x
    return  quadratic(a, b, c)
    
def calc_t(x, v, a, D):
    return quadratic(0.5 * a, v, x - D)

def solve(case):
    D = float(case[0][0])
    N = int(case[0][1])
    A = int(case[0][2])
    ts = [float(c[0]) for c in case[1:N+1]]
    xs = [float(c[1]) for c in case[1:N+1]]
    acs = [float(c) for c in case[N+1]]
    
    ts.append(ts[-1:][0] + 1.0)
    xs.append(xs[-1:][0] + 1.0)
    
    for my_a in acs:
        my_v = 0.0
        my_x = 0.0
        for i in range(len(ts) - 1):
            their_x = xs[i]
            their_v = (xs[i+1] - xs[i]) / (ts[i+1] - ts[i])
            
            if xs[i+1] >= D:
                print '%.6f' % (ts[i] + max(calc_t(my_x, my_v, my_a, D), (D - their_x) / their_v))
                break
            
            dt = calc_dt(my_v, my_a, their_x, their_v)
            
            if ts[i] + dt < ts[i+1]:
                my_x = xs[i+1]
                my_v = their_v
            else:
                dt = ts[i+1] - ts[i]
                my_x = my_x + dt * my_v + 0.5 * dt * my_a
                my_v = my_v + dt * my_a

input = [line.strip().split() for line in sys.stdin]
counter = 0
line = 1
while counter < int(input[0][0]):
    counter += 1
    N = int(input[line][1])
    case = input[line : line + 2 + N]
    print 'Case #%d:' % counter
    solve(case)
    line += N + 2
