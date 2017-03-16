#!/usr/bin/env python

from bisect import bisect_left, bisect_right
from itertools import permutations

t = int(raw_input())

for caseno in xrange(1, t+1):
    n = int(raw_input())
    naomi = sorted(map(float, raw_input().split()))
    naomi_war = naomi[:]
    ken = sorted(map(float, raw_input().split()))
    ken_war = ken[:]
    i = 0
    war = 0
    for i in xrange(n):
        chosen_naomi = naomi_war[0]
        if chosen_naomi > ken_war[-1]:
            k = 0
        else:
            k = bisect_right(ken_war, chosen_naomi)
        chosen_ken = ken_war[k]
        if chosen_naomi > chosen_ken:
            war += 1
        naomi_war.remove(chosen_naomi)
        ken_war.remove(chosen_ken)
    dwar = 0
    for i in xrange(n):
        if naomi[-1] > ken[-1]:
            naomi.remove(naomi[-1])
            dwar += 1
        else:
            naomi.remove(naomi[0])
        ken.remove(ken[-1])
    print "Case #%d: %d %d" % (caseno, dwar, war)
