from math import *
from sys import stdin, stdout

# print(pi)

inp = stdin.readlines()

tests = int(inp[0])
inp = inp[1:]


def calc(r, count):
    return (2 * (2 * r + 1) + (count - 1) * 4) * count // 2

for test in range(tests):
    [r, t] = map(int, inp[test].split())
    left = 0
    lres = calc(r, left)
    right = 10 ** 18
    rres = calc(r, right)
    while left + 1 != right:
        # print("left {} lres {}".format(left, lres))
        # print("right {} rres {}".format(right, rres))
        mid = (left + right) // 2
        mres = calc(r, mid)
        if mres <= t:
            left = mid
            lres = mres
        else:
            right = mid
            rres = mres
    print("Case #{}: {}".format(test + 1, left))
