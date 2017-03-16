#!/usr/bin/python3

from math import log

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def is_power2(n):
    return n & (n - 1) == 0

def rec(n, d):
    if n >= d // 2:
        return 1
    else:
        return rec(n, d // 2) + 1


def answer():
    n, d = [int(x) for x in input().split('/')]
    a = gcd(n, d)
    n, d = n // a, d // a
    if not is_power2(d):
        return 'impossible'
    return str(rec(n, d))

def main():
    T = int(input())
    for i in range(1, T + 1):
        print("Case #%d: %s" % (i, answer()))

main()
