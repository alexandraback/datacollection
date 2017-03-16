import sys
import numpy as np



def solve(case, X, R, C):
    if (R*C) % X != 0:
        return True     # RICHARD

    if X > R and X > C:
        return True     # RICHARD

    min_size = min(R, C)
    if X > min_size:
        if min_size == 1:
            ##
            #
            return X >=3
        if X > min_size*2 - 1:
            ###...  of equal legs. It has max size in all directions for given X.
            #
            #
            return True     # RICHARD


    if X in [1, 2, 3]:
        return False    # GABRIEL

    if X == 4:
        return (min_size == 2)


    if X >= 7:
        ###
        # #
        ##
        assert min_size >= 3
        return True     # RICHARD

    assert False    # haven't decided yet


filename_in = sys.argv[1]
filename_out = filename_in.partition('.')[0] + '.out'
with open(filename_out, "w") as fout:
    with open(filename_in, "r") as fin:
        T = int(fin.readline())
        for case in range(1, T+1):
            X, R, C = [int(x) for x in fin.readline().split()]
            solution = "RICHARD" if solve(case, X, R, C) else "GABRIEL"
            print >> fout, "Case #%i:" % case, solution
