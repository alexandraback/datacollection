#!/usr/bin/python2.7
import sys
from fractions import gcd

def get_res(n, m, k):
    if n > m:
        n, m = m, k
    if n <= 2 or k <= 4:
        return k
    if k == 5:
        return 4
    if k == 6:
        return 5
    if n == 3:
        w = k / 3
        res = w * 2 + 2
        k -= w * 3
        if k > 0:
            k -= 1
        if k > 0:
            k -= 1
            if w + 2 > m:
                res += 1
        return res

    # n == 4
    if k <= 8:
        return 6
    if k  <= 10:
        return 7
    if k <= 12:
        return 8
    if m == 4:
        return 8 + (k - 12)
    # m == 5
    if k <= 14:
        return 9
    if k <= 16:
        return 10
    return 10 + (20 - 16)

if __name__ == "__main__":
    tcn = int(sys.stdin.readline())
    for tc in range(tcn):
        parts = sys.stdin.readline().strip().split()
        n = int(parts[0])
        m = int(parts[1])
        k = int(parts[2])
        print "Case #" + str(tc + 1) + ":", get_res(n, m, k)
