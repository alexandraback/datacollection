import sys
import itertools
from collections import Counter

itertools


def run(filename):
    lines = open(filename + ".in").read().split("\n")[1:]  # remove the T
    fout = open(filename + ".out", "w")
    i = 0
    t = 1
    while i < len(lines):
        numvals = int(lines[i])
        result = solve([x.split() for x in lines[i+1:i+1+numvals]], set(), set())
        print("Case #{}: {}".format(t, result, file=fout))
        i += numvals + 1
        t += 1
#        print("Case #{}: {}".format(t, result))
    fout.close()

def solve(values, firstdups, seconddups):
    high = 0
    for i in range(2**len(values)):
        bmask = bin(i)[2:].zfill(len(values))
        firstreal = set()
        secondreal = set()
        [(firstreal.add(first), secondreal.add(second)) for real, (first, second) in zip(bmask, values) if real == "1"]
        if not [1 for real, (first, second) in zip(bmask, values) if real == "0" and not (first in firstreal and second in secondreal)]:
            # found a duplicate which can't be a duplicate
            high = max(high, bmask.count("0"))
    return high


    return high

    if values[0][0] in firstdups and values[0][1] in seconddups:
        # duplicate
        return solve(values[1:], firstdups, seconddups) + 1
    else:
        newfirstdups = firstdups.copy()
        newseconddups = seconddups.copy()
        newfirstdups.add(values[0][0])
        newseconddups.add(values[0][1])
        return solve(values[1:], newfirstdups, newseconddups)



if __name__ == '__main__':
    run(sys.argv[1])
