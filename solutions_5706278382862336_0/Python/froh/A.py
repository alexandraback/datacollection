#!/usr/bin/env python3

T = int(input())

import fractions

for t in range(T):
    a, b = map(int, input().split('/'))
    # test if a / b is a fraction of the form x / 2**i for some integer i
    # i  is then the number of generations.
    # the last time a 'full elf' has been in the ancestry is the ld(x)-i
    x = fractions.Fraction(a,b)
    generations = x.denominator.bit_length() - 1
    if 1 << generations == x.denominator:
        last_full_elf = x.numerator.bit_length()
        distance_to_last_full_elf = generations - last_full_elf + 1
        print("Case #{}: {}".format(t+1, distance_to_last_full_elf))
    else:
        print("Case #{}: impossible".format(t+1))
