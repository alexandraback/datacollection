import sys
import numpy as np


def partial_solve(P, P_prev):
    if (len(P) == 0):
        return P_prev
    P_max = P[-1]
    t_best = max(P_max, P_prev)
    for div in xrange(2, P_max):
        if P_max // div < 2:
            break
        P_max_dived = P_max // div + P_max % div
        t_special = div - 1
        t = t_special + partial_solve(P[:-1], max(P_max_dived, P_prev))
        t_best = min(t_best, t)
    return t_best


def solve(case, D, P):
    assert len(P) == D
    P = np.array(P)
    P.sort()
    return partial_solve(P, 0)



filename_in = sys.argv[1]
filename_out = filename_in.partition('.')[0] + '.out'
with open(filename_out, "w") as fout:
    with open(filename_in, "r") as fin:
        T = int(fin.readline())
        for case in range(1, T+1):
            D = int(fin.readline())
            P = [int(x) for x in fin.readline().split()]
            print >> fout, "Case #%i:" % case, solve(case, D, P)
