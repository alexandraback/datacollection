import sys
import numpy as np



def solve(case, X, R, C):
    N = R*C
    if N % X != 0:
        return True     # RICHARD

    if X > R and X > C:
        return True     # RICHARD

    min_size = min(R, C)
    max_size = max(R, C)
    if X > min_size:
        if min_size == 1:
            ##
            #
            return X >=3
        if X >= (min_size+1)*2 - 1:
            ###  of equal legs. It has max size in all directions for given X.
            #
            #
            return True     # RICHARD


    if X in [1, 2, 3]:
        return False    # GABRIEL

    if X == 4:
        # min fillable is 3x4
        # this does't work in 2x? :
        #    #
        #   ###
        return min_size <= 2

    if X == 5:
        if min_size <= 3:
            # min fillable is 3x10
            return max_size < 10
        else:
            # min fillable is 4x5
            return False    # GABRIEL

    if X == 6:
        if min_size == 3:
            return True     # RICHARD
        elif min_size == 4:
            # min fillable is 4x6
            return max_size < 6
        else:
            assert max_size >= 6
            return False    # GABRIEL

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
