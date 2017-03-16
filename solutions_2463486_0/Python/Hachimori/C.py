#!/usr/bin/env python

import bisect


def read():
    bgn, end = map(int, raw_input().split())
    return bgn, end


def work((bgn, end), cases):
    tbl = [0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

    bIdx = bisect.bisect_left(tbl, bgn)
    eIdx = bisect.bisect_right(tbl, end)

    print "Case #%d: %d" % (cases, eIdx - bIdx)


if __name__ == "__main__":
    for cases in range(int(raw_input())):
        work(read(), cases + 1)
