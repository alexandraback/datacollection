#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import Counter

#table = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
#
#chars = set()
#for t in table:
#    chars.update(t)
#print(chars)
#
#for ch in chars:
#    print("ch", ch, ":")
#    for t in table:
#        if ch in t:
#            print("  appear in ", t)

def subt(S, key, found, num):
    t = 1
    key_c = Counter(key)

    mn = 100000000
    for ch in key_c:
        mn = min(mn, S[ch] // key_c[ch])

    for ch in key_c:
        S[ch] -= key_c[ch] * mn
    found += [num] * mn


def solve():
    S = input()
    S = S.strip()

    S = Counter(S)

    found = []
    subt(S, "SIX", found, 6)
    subt(S, "TWO", found, 2)
    subt(S, "FOUR", found, 4)
    subt(S, "ZERO", found, 0)
    subt(S, "EIGHT", found, 8)

    subt(S, "FIVE", found, 5)
    subt(S, "SEVEN", found, 7)
    subt(S, "ONE", found, 1)
    subt(S, "NINE", found, 9)
    subt(S, "THREE", found, 3)
    
    found.sort()
    return "".join([str(x) for x in found])



def main():
    T = int(input())
    for t in range(T):
        print ("Case #" + str(t+1) + ":", solve())

main()

