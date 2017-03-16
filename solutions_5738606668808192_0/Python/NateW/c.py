#!/usr/bin/env python

import math
import sys


def factor(n):
    for i in xrange(2, int(math.sqrt(n)) + 2):
        if n % i == 0:
            return i
    return None


def generate(n):
    value = [False] * n
    value[0] = True
    value[n - 1] = True
    yield "".join(["1" if c else "0" for c in value])
    while True:
        index = n - 2
        while index > 0:
            old = value[index]
            value[index] = not value[index]
            if not old:
                break
            index -= 1
        if index == 0:
            break
        yield "".join(["1" if c else "0" for c in value])


def solve(n, j):
    results = []
    for possible in generate(n):
        #print "Examining %s" % possible
        proofs = []
        for base in range(2, 11):
            f = factor(int(possible, base))
            if not f:
                break
            proofs.append(f)
        if len(proofs) == 9:
            #print "Adding %s to results: %s" % (possible, proofs)
            results.append((possible, proofs))
            if len(results) >= j:
                break
    return results


def main():
    assert factor(8) == 2
    assert factor(9) == 3
    assert factor(21) == 3
    assert factor(7) == None
    assert factor(13) == None

    lines = sys.stdin.readlines()
    tests = int(lines[0])
    for i in xrange(tests):
        n, j = [int(p) for p in lines[i + 1].split()]
        print "Case #%d:" % (i + 1)
        for jamcoin, proof in solve(n, j):
            for basei, base in enumerate(range(2, 11)):
                if int(jamcoin, base) % proof[basei] != 0:
                    assert False, ("Result %s converted to base %d is %d, "
                        "divisor %d, doesn't work!") % (value, base,
                        int(jamcoin, base), proof[basei])
            print "%s %s" % (jamcoin, " ".join([str(k) for k in proof]))


if __name__ == "__main__":
    main()
