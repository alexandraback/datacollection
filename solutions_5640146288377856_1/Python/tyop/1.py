#!/usr/bin/env python
# >

import sys


def work2(cols, rows, ship):
    count = 0
    if cols == ship:
        return rows - 1 + cols
    elif ship == 1:
        return cols * rows
    elif cols > ship:
        per_row = cols / ship
        # print "cols %d / ship %d / per_row %d " % (cols, ship, per_row)
        count += per_row * rows
        if cols % ship == 0:
            count += ship - 1
        else:
            count += ship
    return count

flag = 0
for line in file(sys.argv[1]):
    if flag == 0:
        ntests = int(line)
        flag = 1
        continue ;
    else:
        rows, cols, ship = line.split(" ")
        cols = int(cols)
        rows = int(rows)
        ship = int(ship)
        result = work2(cols, rows, ship)
        print "Case #%d: %d" % (flag, result)
        flag += 1
