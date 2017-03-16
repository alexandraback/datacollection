#!/usr/bin/python
""" template.py < input-file """

from numpy import *

CAR_LENGTH = 5.0

def raw_input_words():
    return raw_input().strip().split()

def raw_input_ints():
    return map(int, raw_input_words())

def intersection_time(s1, p1, s2, p2):
    return (p2 - p1) / (s1 - s2)

def get_interesting_times(speeds, positions):
    result = set([])
    for i in range(len(speeds)):
        for j in range(len(speeds)):
            if i >= j:
                continue
            if abs(speeds[i]-speeds[j]) > 1e-6:
                it = intersection_time(speeds[i], positions[i], speeds[j], positions[j])
                if it > 0:
                    result.add(it)
                it = intersection_time(speeds[i], positions[i] + CAR_LENGTH, speeds[j], positions[j])
                if it > 0:
                    result.add(it)
                it = intersection_time(speeds[i], positions[i], speeds[j], positions[j] + CAR_LENGTH)
                if it > 0:
                    result.add(it)
    return result

def has_crash(positions):
    p = positions.copy()
    p.sort()
    # print p
    if len(p) <= 2:
        return False
    for i in range(len(positions)-2):
        if p[i+2] - p[i] <= CAR_LENGTH + 1e-10:
            return True
    return False

def solve_one():
    N = int(raw_input())
    lanes, speeds, positions = [], [], []
    for i in range(N):
        l, s, p = raw_input_words()
        lanes.append(l)
        speeds.append(float(s))
        positions.append(float(p))

    speeds = array(speeds)
    positions = array(positions)
    
    interesting_times = get_interesting_times(speeds, positions)

    # print ""
    # print speeds
    # print positions
    # print sorted(interesting_times)
    # print ""

    for t in sorted(interesting_times):
        new_positions = positions + t * speeds
        # print t
        if has_crash(new_positions):
            return t

    return "Possible"

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(T):
        print "Case #%d:" % (i+1,), solve_one()

