#!/usr/bin/env python
# -*- Encoding: utf-8 -*-

from __future__ import print_function, unicode_literals

import sys
import heapq

from collections import defaultdict


class Building(object):

    def __init__(self, id, maxB):
        self.id = id
        self.maxB = maxB
        self.tgts = set()
        self.routes = 0

    def add_slide(self):
        for i in range(self.id + 1, self.maxB + 1):
            if i not in self.tgts:
                self.tgts.add(i)
                return i
        return False

    def remove_slide(self, id):
        self.tgts.remove(id)


def solve(buildings, M, m=0):
    before = m
    for building in buildings[::-1]:
        before_m = m
        id = building.add_slide()
        if not id:
            continue

        if buildings[id - 1].routes > 0:
            m /= buildings[id - 1].routes
        buildings[id - 1].routes += 1
        m *= buildings[id - 1].routes
        if m == M:
            return True
        elif m > M:
            building.remove_slide(id)
            m = before_m

    if m == 0:
        m = 1
    if m == M:
        return True
    elif m > M:
        return False
    elif m == before:
        return False

    return solve(buildings, M, m)


if __name__ == '__main__':
    f = sys.stdin
    T = int(f.readline())

    for t in range(T):
        B, M = map(int, f.readline().strip().split(" "))
        buildings = [Building(id=i, maxB=B) for i in range(1, B + 1)]
        ans = solve(buildings, M, m=0)

        print("Case #{}: {}".format(t + 1, "POSSIBLE" if ans else "IMPOSSIBLE"))
        if ans:
            for i, b in enumerate(buildings):
                print("".join("1" if u.id in b.tgts else "0" for u in buildings))
