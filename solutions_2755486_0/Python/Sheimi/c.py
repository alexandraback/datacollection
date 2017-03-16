#!/usr/bin/env python
import math


def print_result(case_no, msg):
    print "Case #%d: %s" % (case_no, msg)


def run_case(case_no):
    num = int(raw_input())
    tribes = []
    for i in range(num):
        d, n, w, e, s, dd, dp, ds = [int(i) for i in raw_input().split(' ')]
        tribes.append((d, n, w, e, s, dd, dp, ds))

    attacks = {}
    for d, n, w, e, s, dd, dp, ds in tribes:
        for i in range (n):
            tmp_r = (w, e, s)
            if d in attacks:
                attacks[d].append(tmp_r)
            else:
                attacks[d] = [tmp_r]
            w += dp
            e += dp
            s += ds
            d += dd

    days = attacks.keys()
    days.sort()
    success = 0
    wall = {}
    def can_break_wall(w, e, s):
        for i in range(w, e):
            if i not in wall:
                return True
            if s > wall[i]:
                return True
        return False

    def build_wall(w, e, s):
        for i in range(w, e):
            if i not in wall:
                wall[i] = s
                continue
            if wall[i] < s:
                wall[i] = s
    for d in days:
        attacks2 = attacks[d]
        to_build = []
        for w, e, s in attacks2:
            can = can_break_wall(w, e, s)
            if can:
                success += 1
                to_build.append((w, e, s))
        for w, e, s in to_build:
            build_wall(w, e, s)

    result = str(success)
    print_result(case_no, result)


if __name__ == '__main__':
    num = int(raw_input())
    for i in xrange(num):
        run_case(i + 1)
