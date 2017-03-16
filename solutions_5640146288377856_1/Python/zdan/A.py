import sys
import numpy as np



def solve(R, C, W):
    if C == W:
        return W + (R-1)
    if C % W == 0:
        return (C // W) * R - 1 + W
    else:
        return (C // W) * R + W


if __name__ == '__main__':
    filename_in = sys.argv[1]
    filename_out = filename_in.partition('.')[0] + '.out'
    with open(filename_out, "w") as fout:
        with open(filename_in, "r") as fin:
            T = int(fin.readline())
            for case in range(1, T+1):
                R, C, W = [int(x) for x in fin.readline().split()]
                print >> fout, "Case #%i:" % case, solve(R, C, W)
