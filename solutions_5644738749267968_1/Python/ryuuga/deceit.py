#!/usr/bin/pypy

def read_line():
    s = raw_input()
    while s.strip() == "":
        s = raw_input()
    return s

def read_int():
    return int(read_line())

def read_floats():
    return [float(s) for s in read_line().split()]

def deceit_points(naomi, ken):
    # naomi can choose lightest and repeatedly force ken to play his heaviest block.
    N = len(naomi)
    wins = 0

    start = 0
    end = N-1
    for k in reversed(ken):
        if naomi[end] > k:
            wins += 1
            end -= 1
        else:
            start += 1
    return wins

def war_points(naomi, ken):
    # It doesn't seem like naomi's playing order will matter.
    N = len(ken)
    start = 0
    losses = 0
    for play in naomi:
        while start < N and ken[start] < play:
            start += 1
        if start < N:
            losses += 1
            start += 1
    wins = N - losses
    return wins

def solve():
    N = read_int()
    naomi = tuple(sorted(read_floats()))
    ken = tuple(sorted(read_floats()))
    assert N == len(naomi) == len(ken)

    return deceit_points(naomi,ken), war_points(naomi, ken)

T = read_int()
for i in range(1, T+1):
    deceit, war = solve()
    print "Case #{0}: {1} {2}".format(i, deceit, war)
