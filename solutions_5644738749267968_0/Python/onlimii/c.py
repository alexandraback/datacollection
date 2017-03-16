#!/usr/bin/env python

def locate(value, list, start):
    for i in xrange(start, len(list)-1):
        if value > list[i]:
            return i + 1
        elif list[i + 1] < value < list[i]:
            return i + 2
    return len(list) if value > list[-1] else -1

with open("D-small-attempt0.in", "r") as fin:
    cases = int(fin.readline())
    fout = open("D-small-attempt0.out", "w")

    for i in xrange(cases):
        N = int(fin.readline())
        naomi = map(float, fin.readline().split())
        ken = map(float, fin.readline().split())
        naomi.sort(reverse=True)
        ken.sort(reverse=True)
        war = 0
        t = 0
        for k in ken:
            t = locate(k, naomi, t)
            if 0 <= t < N:
                war += 1
            elif t == N:
                war += 1
                break
            else:
                break
        war = N - war
        dwar = 0
        t = 0
        for n in naomi:
            t = locate(n, ken, t)
            if 0 <= t < N:
                dwar += 1
            elif t == N:
                dwar += 1
                break
            else:
                break
        fout.write("Case #%d: %d %d\n" % (i+1, dwar, war))


