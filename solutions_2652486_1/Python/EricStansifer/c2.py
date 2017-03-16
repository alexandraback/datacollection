#!/usr/bin/python3

from common import *

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b > 0:
        q = a // b
        r = (a - b * q)
        a, b = b, r
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcms(xs):
    l = 1
    for x in xs:
        l = lcm(l, x)
    return l

def intlog(b, x):
    p = 0
    b_pow = 1
    while b_pow <= x:
        p += 1
        b_pow *= b
    return (p - 1)

def prime_pow(b, x):
    p = 0
    while (x % b) == 0:
        p += 1
        x //= b
    return p


def solve1(xs):
    l = lcms(xs)
    num_2 = prime_pow(2, l)
    num_3 = prime_pow(3, l)
    num_5 = prime_pow(5, l)
    num_7 = prime_pow(7, l)

    num_found = num_3 + num_5 + num_7
    ans = ""
    for i in range(0, num_5):
        ans += "5"
    for i in range(0, num_7):
        ans += "7"

    num_6 = 0
    if num_3 > 0:
        # Found at least one 3.
        # Need to determine how many of the 3s are sixes.
        num_div_by_3 = 0
        num_not_div_by_3 = 0
        avg2_with_3 = 0
        avg2_without_3 = 0
        for x in xs:
            if (x % 3) == 0:
                num_div_by_3 += 1
                avg2_with_3 += prime_pow(2, x)
            else:
                num_not_div_by_3 += 1
                avg2_without_3 += prime_pow(2, x)

        if num_div_by_3 > 0:
            avg2_with_3 /= num_div_by_3
        if num_not_div_by_3 > 0:
            avg2_without_3 /= num_not_div_by_3

        if num_3 == 1:
            if avg2_with_3 > avg2_without_3 + 0.5:
                num_6 = 1
            else:
                num_6 = 0
        elif num_3 == 2:
            if avg2_with_3 > avg2_without_3 + 0.75:
                num_6 = 2
            elif avg2_with_3 > avg2_without_3 + 0.25:
                num_6 = 1
            else:
                num_6 = 0
        elif num_3 == 3:
            if avg2_with_3 > avg2_without_3 + (5 / 6):
                num_6 = 3
            elif avg2_with_3 > avg2_without_3 + 0.5:
                num_6 = 2
            elif avg2_with_3 > avg2_without_3 + (1 / 6):
                num_6 = 1
            else:
                num_6 = 0
        else:
            num_6 = num_3 // 2

    rem_2 = num_2 - num_6
    if rem_2 < 0:
        rem_2 = 0

    for i in range(0, num_6):
        ans += "6"
    for i in range(num_6, num_3):
        ans += "3"

    if num_found == 12:
        return ans

    # avg2 = rem_2 / (12 - num_found)

    for i in range(0, (12 - num_found) // 3):
        ans += "2"
    for i in range((12 - num_found) // 3, (2 * (12 - num_found)) // 3):
        ans += "4"
    for i in range((2 * (12 - num_found)) // 3, 12 - num_found):
        ans += "8"

    return ans

def testcase(x):
    r, n, m, k = readintegers()
    writeline("Case #%d:" % x)
    for i in range(r):
        xs = readintegers()
        ans = solve1(xs)
        writeline(ans)

run_tests(testcase)
