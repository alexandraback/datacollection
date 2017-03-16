#!/usr/bin/python2.7
import sys
from fractions import gcd

def get_res(p, q):
    x = gcd(p, q)
    p /= x
    q /= x
    x = q
    while x > 1 and x % 2 == 0:
        x /= 2
    if x != 1:
        return "impossible"
    while q < (2 ** 40):
        q *= 2
        p *= 2
    res = 40
    while p > 1:
        p /= 2
        q /= 2
        res -= 1
    return res

if __name__ == "__main__":
    tcn = int(sys.stdin.readline())
    for tc in range(tcn):
        line = sys.stdin.readline()
        p, q = map(int, line.strip().split("/"))
        print "Case #" + str(tc + 1) + ":", get_res(p, q)
