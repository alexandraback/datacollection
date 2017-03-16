import sys
from itertools import *

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################

def best_interval(interval, R, E, estart, eend):
    if len(interval) == 0:
        return 0

    if len(interval) == 1:
        return interval[0] * (estart - eend)

    max_idx = 0
    for i, value in enumerate(interval):
        if value > interval[max_idx]:
            max_idx = i
 
    max_from_start = min(estart + R * max_idx, E)
    min_from_end = max(eend - R * (len(interval) - max_idx - 1), 0)

    res = (max_from_start - min_from_end) * interval[max_idx] 
    res += best_interval(interval[:max_idx], R, E, estart, max_from_start - R) 
    res += best_interval(interval[max_idx + 1:], R, E, min_from_end + R, eend)
    return res


def read_input():
    E, R, N = int_input()
    v = int_input()
    return E, R, v


def solve(E, R, v):
    return best_interval(v, R, E, E, 0)



#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

