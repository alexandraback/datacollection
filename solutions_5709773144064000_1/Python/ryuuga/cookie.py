#!/usr/bin/pypy

def read_line():
    s = raw_input()
    while s == "":
        s = raw_input()
    return s

def read_int():
    return int(read_line())

def read_floats():
    return [float(s) for s in read_line().split()]

def solve():
    C, F, X = read_floats()
    rate = 2
    best = X / rate
    elapsed = 0     # time spent to get to current rate
    while elapsed <= best:
        time_building = elapsed + C / rate
        time_win = elapsed + X / rate

        best = min(best, time_win)
        elapsed = time_building
        rate += F
    return "{0:.7f}".format(best)

T = read_int()
for i in range(1, T+1):
    solution = solve()
    print "Case #{0}: {1}".format(i, solution)
