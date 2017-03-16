#!/usr/bin/env python3

import sys
import math
import bisect

def mul(p,q):
    if p == "1":
         return (1, q)
    elif p == "i":
        if q == "i":
            return (-1, "1")
        elif q == "j":
            return (1, "k")
        elif q == "k":
            return (-1, "j")
    elif p == "j":
        if q == "i":
            return(-1, "k")
        elif q == "j":
            return (-1, "1")
        elif q == "k":
            return (1, "i")
    elif p == "k":
         if q == "i":
             return (1, "j")
         elif q == "j":
             return (-1, "i")
         elif q == "k":
             return (-1, "1")

    return Nil

def red(s):
    sign = 1
    char = "1"
    for c in s:
        s, char = mul(char, c)
        sign *= s
    return (sign, char)

def is_appear(s, target):
    char = "1"
    for i,c in enumerate(s):
        _, char = mul(char, c)
        if char == target:
            return True, i
    return False, -1

def solve(x, s):
    if len(s) == 1:
        return False

    b, ip = is_appear(s, "i")
    if not b:
        if x < 2: return False
        b, ip = is_appear(s+s, "i")
        if not b:
            return False

    rs = s[::-1]
    b, kp = is_appear(rs, "k")
    if not b:
        if x < 2: return False
        b, kp = is_appear(rs+rs, "k")
        if not b:
            return False

    if ip+kp+2 > len(s)*x:
        return False

    sign, char = red(s)

    if char == "1":
        return (sign ** x) == -1

    if x % 4 == 2:
        return True

    return False

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        _, x = [int(x) for x in sys.stdin.readline().split(' ')]
        s = sys.stdin.readline()
        ret = solve(x,s[:-1])
        print("Case #{0}: {1}".format(i+1, "YES" if ret else "NO"))

if __name__ == '__main__':
    main()
