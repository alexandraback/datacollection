import sys
import itertools
import numpy as np


def solve(C, D, V, coins):
    assert C == 1
    for v in range(1, V+1):
        for coin in reversed(coins):
            if v == 0:
                break
            elif v >= coin:
                v -= coin
        if v > 0:
            coins.append(v)
            coins.sort()
    return len(coins) - D



if __name__ == '__main__':
    filename_in = sys.argv[1]
    filename_out = filename_in.partition('.')[0] + '.out'
    with open(filename_out, "w") as fout:
        with open(filename_in, "r") as fin:
            T = int(fin.readline())
            for case in range(1, T+1):
                C, D, V = [int(x) for x in fin.readline().split()]
                coins = [int(x) for x in fin.readline().split()]
                print >> fout, "Case #%i:" % case, solve(C, D, V, coins)
