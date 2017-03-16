# -*- coding: utf-8 -*-
import sys,copy,math,heapq,itertools as it,fractions,re,bisect,collections as coll

alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

zero = "ZERO"
one  = "ONE"
two  = "TWO"
three= "THREE"
four = "FOUR"
five = "FIVE"
six  = "SIX"
seven= "SEVEN"
eight= "EIGHT"
nine = "NINE"

T = int(raw_input())
for case in xrange(T):
    S = raw_input()
    cnt = {c:0 for c in alpha}
    for s in S: cnt[s] += 1

    ans = ""
    for i in xrange(cnt["Z"]):
        for c in zero: cnt[c] -= 1
        ans += "0"

    for i in xrange(cnt["G"]):
        for c in eight: cnt[c] -= 1
        ans += "8"

    for i in xrange(cnt["X"]):
        for c in six: cnt[c] -= 1
        ans += "6"

    for i in xrange(cnt["S"]):
        for c in seven: cnt[c] -= 1
        ans += "7"

    for i in xrange(cnt["V"]):
        for c in five: cnt[c] -= 1
        ans += "5"

    for i in xrange(cnt["F"]):
        for c in four: cnt[c] -= 1
        ans += "4"

    for i in xrange(cnt["R"]):
        for c in three: cnt[c] -= 1
        ans += "3"

    for i in xrange(cnt["T"]):
        for c in two: cnt[c] -= 1
        ans += "2"

    for i in xrange(cnt["O"]):
        for c in one: cnt[c] -= 1
        ans += "1"

    for i in xrange(cnt["I"]):
        for c in nine: cnt[c] -= 1
        ans += "9"

    ans = "".join(sorted(ans))
    print "Case #%d: %s" % (case + 1, ans)
