#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Google Code Jam Qualification Round 2013
# Written by Anders Sjöqvist, anders@sjoqvi.st
#
# The file generates a database file the first time it runs. The generation is
# typically slower than allowed, so it's a good idea to run it before the
# input is fetched.
import bisect

table = [1L*1L, 2L*2L, 3L*3L, 11L*11L, 22L*22L]

def palin(num):
    numstr = str(num)
    if numstr == numstr[::-1]:
        table.append(num)

def build_table():
    for i in range(2, 100000000):
        part = bin(i)[2:]
        full = part + part[::-1]
        num = long(full)
        palin(num*num)

        full = part[:-1] + part[::-1]
        num = long(full)
        palin(num*num)

        if part[-1:]=='1':
            part2 = part[:-1] + '2'
            full = part2[:-1] + part2[::-1]
            num = long(full)
            palin(num*num)

        part = '2' + part[1:]
        full = part + part[::-1]
        num = long(full)
        palin(num*num)

        full = part[:-1] + part[::-1]
        num = long(full)
        palin(num*num)

    table.sort()

try:
    table = [long(line) for line in open('fair_and_square.db', 'r')]
except IOError, e:
    build_table()
    fp = open('fair_and_square.db', 'w')
    for item in table:
        fp.write("%s\n" % item)

[cases] = map(int, raw_input().split())
for i in range(0, cases):
    [a, b] = map(long, raw_input().split())
    print "Case #%d: %d" % (i+1, bisect.bisect_right(table, b) -
                            bisect.bisect_left(table, a))
