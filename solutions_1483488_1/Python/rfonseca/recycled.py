#!/usr/bin/env python3

import sys
from math import log10

def recycled(a, b):
    # Can't recycle numbers with just one digit
    if len(b) < 2:
        return 0
    intb = int(b)
    generated = set()
    # Generate all recycles
    for n in range(int(a), intb):
        #print("Processing number", n)
        num = str(n)
        # For each digit starting from the second
        for i, d in enumerate(num[1:]):
            #print("Processing digit", d)
            # Possible valid number (A <= n < m <= B)
            if d >= a[0] and d <= b[0]:
                # Prepend suffix
                m = int(num[i+1:] + num[:i+1])
                #print("Generated from", n, "is", m)
                if m > n and m <= intb:
                    #print("Counting number", m)
                    generated.add((n, m))
    return len(generated)

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for case in range(1, ncases + 1):
        #a, b = [int(x) for x in sys.stdin.readline().strip().split(' ')]
        a, b = sys.stdin.readline().strip().split(' ')
        #print("Limits [", a, b, "]")
        print("Case #", case, ": ", recycled(a, b), sep="")
