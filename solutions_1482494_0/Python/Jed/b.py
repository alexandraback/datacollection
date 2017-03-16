#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: b.py
# $Date: Sat Apr 28 10:33:37 2012 +0800
# $Author: jiakai <jia.kai66@gmail.com>


def work(a, b):
    ans = [0]

    class PartLevel:
        lvl = None
        val = None
        def __init__(self, lvl, val):
            self.lvl = lvl
            self.val = val

    class LevelInfo:
        rating = 0
        num = None

        def solve(self, rating):
            ret = rating - self.rating
            if ret > 0:
                self.rating = rating
                ans[0] += 1
                return ret
            return 0

    
    lvlinfo = [LevelInfo() for i in range(len(a))]

    apart = list()
    bpart = list()
    for i in range(len(a)):
        apart.append(PartLevel(lvlinfo[i], a[i]))
        bpart.append(PartLevel(lvlinfo[i], b[i]))


    for i in apart, bpart:
        i.sort(cmp = lambda x, y: cmp(x.val, y.val))

    for i in range(len(b)):
        bpart[i].lvl.num = i

    cur_star = 0
    apos = 0
    for i in bpart:
        while cur_star < i.val:
            choose_a = -1
            for j in range(apos, len(a)):
                if cur_star >= apart[j].val:
                    if (choose_a == -1 or
                            apart[j].lvl.num > apart[choose_a].lvl.num):
                        choose_a = j
                else:
                    break

            if choose_a == -1:
                return 'Too Bad'

            [apart[apos], apart[choose_a]] = [apart[choose_a], apart[apos]]
            cur_star += apart[apos].lvl.solve(1)
            apos += 1

        cur_star += i.lvl.solve(2)

    return ans[0]


if __name__ == '__main__':
    ncase = int(raw_input())

    for casenu in range(ncase):
        t = int(raw_input())
        a = list()
        b = list()
        for i in range(t):
            [x, y] = [int(s) for s in raw_input().split()]
            a.append(x)
            b.append(y)

        print 'Case #{0}: {1}'.format(casenu + 1, work(a, b))

