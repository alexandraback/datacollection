#!/usr/bin/env python
# -*- coding: utf-8 -*-

def play_war(naomi, ken):
    # naomi = list(naomi)
    # ken = list(ken)
    points = 0
    while naomi:
        w = naomi.pop()
        if w > ken[-1]:
            points += 1
            ken.pop(0)
        else:
            i = 0;
            while ken[i] < w:
                i += 1
            ken.pop(i)
    return points

def play_deceitful(naomi, ken):
    naomi = list(naomi)
    ken = list(ken)
    points = 0
    while naomi:
        if naomi[0] < ken[0]:
            naomi.pop(0)
        else:
            naomi.pop(0)
            ken.pop(0)
            points += 1
        #print naomi[i], ken[i]
    return points

def solve(n):
    naomi = sorted(map(float, raw_input().split()))
    ken = sorted(map(float, raw_input().split()))
    return "%d %d" % (play_deceitful(naomi, ken) , play_war(naomi, ken))


if __name__ == "__main__":
    testcases = input()
    for case_n in xrange(1, testcases+1):
        n = input()
        print("Case #%i: %s" % (case_n, solve(n)))
