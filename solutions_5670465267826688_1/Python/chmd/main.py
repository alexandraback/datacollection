#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import sys

res_mul = {
        "1": {
            "1": "1",
            "i": "i",
            "j": "j",
            "k": "k"
            },
        "i": {
            "1": "i",
            "i": "-1",
            "j": "k",
            "k": "-j"
            },
        "j": {
            "1": "j",
            "i": "-k",
            "j": "-1",
            "k": "i"
            },
        "k": {
            "1": "k",
            "i": "j",
            "j": "-i",
            "k": "-1"
            }
        }


def mul(a, b):
    sign = 1
    if len(a) == 2:
        sign = sign * (-1)
        a = a[1]
    if len(b) == 2:
        sign = sign * (-1)
        b = b[1]
    res = res_mul[a][b]
    if len(res) == 2:
        sign = sign * (-1)
        res = res[1]
    if sign < 0:
        return "-" + res
    else:
        return res


def power(a, n):
    if a == "1":
        return "1"
    if a == "-1":
        if n % 2 == 0:
            return "1"
        else:
            return "-1"
    # else
    if len(a) == 1:
        n = n % 4
        if n == 0:
            return "1"
        if n == 1:
            return a
        if n == 2:
            return "-1"
        if n == 3:
            return "-" + a
    else:
        return mul(power("-1", n), power(a[1], n))


def read_tests(instance_file):
    with open(instance_file) as f:
        n = int(f.next().strip('\n'))
        for _ in range(n):
            l, x = [int(i) for i in f.next().strip().split(" ")]
            s = f.next().strip('\n')
            yield (x, s)


def find_i_from_start(s):
    """
    returns i such that s[:i] reduces to "i"
    """
    n = len(s)
    if s[0] == "i":
        return 1
    r = s[0]
    for i in range(1, n - 1):
        r = mul(r, s[i])
        if r == "i":
            return i + 1
    return 0

def find_k_from_end(s):
    """
    returns i such that s[i:] reduces to "k"
    """
    n = len(s)
    if s[n-1] == "k":
        return n-1
    r = s[n-1]
    for i in range(1, n - 1):
        r = mul(s[n-1-i], r)
        if r == "k":
            return n - 1 - i
    return len(s)




def reduces_to_ijk(x, s):

    if x * len(s) < 3:
        return False

    if x <= 10:
        xs = x*s

        i = find_i_from_start(xs)
        if i == 0:
            return False

        k = find_k_from_end(xs)
        if k == len(xs):
            return False

        if i >= k:
            return False

        return reduce(mul, xs[i:k]) == "j"

    else:
        look = 4*s
        i = find_i_from_start(look)
        if i == 0:
            return False
        k = find_k_from_end(look)
        if k == len(look):
            return False

        beg = reduce(mul, look[i:])
        end = reduce(mul, look[:k])

        mid = power(reduce(mul, s), x - 8)
        return reduce(mul, [beg, mid, end]) == "j"


def solve_instance(instance):
    x, s = instance

    if reduces_to_ijk(x, s):
        return "YES"
    else:
        return "NO"



if __name__ == "__main__":
    if len(sys.argv[1:]) != 1:
        exit("Expected 1 argument, got %i" % len(sys.argv[1:]))

    instance_file = sys.argv[1]

    for i, instance in enumerate(
            read_tests(instance_file), start=1
            ):
        print("Case #%i: %s" % (i, solve_instance(instance)))
