import sys
from functools import *
from itertools import *
import heapq



def to_bin(m):
    cnt = 1
    bin_repr = 61 * [0]
    while m != 0:
        bin_repr[cnt] = m % 2
        m /= 2
        cnt += 1
    return bin_repr


def solve(b, m):
    diff = 2**(b - 2) - m
    if diff < 0:
        return False
    pa = to_bin(m)
    if diff == 0:
        i = 0
        while pa[i] != 1:
            pa[i] = 1
            i += 1
        pa[i] = 0
    res = ""
    for j in range(0, b):
        for i in range(0, b):
            if i == b - 1:
                res += str(pa[j])
            else:
                if i > j:
                    res += "1"
                else:
                    res += "0"
        res += "\n"
    return res


if __name__ == '__main__':
    t = int(raw_input())
    for i in range(0, t):
        solved = solve(*map(int, raw_input().split()))
        if not solved:
            res = "IMPOSSIBLE"
        else:
            res = "POSSIBLE\n"
            res += solved
        print("Case #{0}: {1}".format(i + 1, res))
