#!/usr/bin/python3

import sys

convertTable = {
    '1': 1,
    'i': 2,
    'j': 3,
    'k': 4,
}

multTable = {
    (1, 1): 1,
    (1, 2): 2,
    (1, 3): 3,
    (1, 4): 4,
    (2, 1): 2,
    (2, 2): -1,
    (2, 3): 4,
    (2, 4): -3,
    (3, 1): 2,
    (3, 2): -4,
    (3, 3): -1,
    (3, 4): 2,
    (4, 1): 4,
    (4, 2): 3,
    (4, 3): -2,
    (4, 4): -1
}


def multTwoCodes(a, b):
    sign = 1 if ((a < 0) == (b < 0)) else -1
    return sign * multTable[(abs(a), abs(b))]


T = int(input())
for case in range(T):
    x = int(input().split()[1])  # x times
    inputStr = input()

    codes = list(map(lambda char: convertTable[char], inputStr))

    prod = 1
    for code in codes:
        prod = multTwoCodes(prod, code)

    if (prod == -1 and x % 2 == 0) or (prod == 1 or (prod != -1 and x % 4 != 2)):
        print ("Case #%d: NO" % (case + 1))
        continue

    codes = codes * min(11 if prod == -1 else 22, x)  # SUDDENLY, HUH!
    minIndexI = -1
    maxIndexK = -1
    prod = 1
    for i, code in enumerate(codes):
        prod = multTwoCodes(prod, code)
        if prod == convertTable['i'] and minIndexI == -1:
            minIndexI = i
        if prod == convertTable['k']:
            maxIndexK = i

    ans = minIndexI != -1 and maxIndexK != -1 and minIndexI < maxIndexK
    # sys.stderr.write("prod == %d; minIndexI == %d; maxIndexK == %d" % (prod, minIndexI, maxIndexK))
    print ("Case #%d: %s" % (case + 1, "YES" if ans else "NO"))
