#!/usr/bin/env python
#coding: utf-8


def read():
    initV, numV = map(int, raw_input().split())
    vList = map(int, raw_input().split())
    return initV, vList


def work(cases, (initV, vList)):
    if initV == 1:
        print "Case #%d: %d" % (cases, len(vList))
        return

    ans = 1<<30
    nOpe = 0
    preV = initV

    while 1:
        curV = preV
        curV += sum([v for v in vList if v < preV])
        vList = [v for v in vList if v >= preV]

        if not vList:
            ans = min(ans, nOpe)
            break

        ans = min(ans, nOpe + len(vList))

        if curV <= min(vList):
            nOpe += 1
            preV = curV * 2 - 1
        else:
            preV = curV

    print "Case #%d: %d" % (cases, ans)


if __name__ == "__main__":
    for cases in range(int(raw_input())):
        work(cases + 1, read())
