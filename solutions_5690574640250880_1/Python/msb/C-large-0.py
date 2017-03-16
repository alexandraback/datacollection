#!/usr/bin/env python

def minesweeper(r, c, m):
    empty = r * c - m
    if empty == 1:
        pass
    elif r == 1 or c == 1:
        if empty < 2:
            print "Impossible"
            return
    elif r == 2 or c == 2:
        if empty % 2 or empty == 2:
            print "Impossible"
            return
    elif empty < 9:
        if empty % 2 or empty == 2:
            print "Impossible"
            return
    if empty == 1:
        print "c" + "*" * (c - 1)
        for i in xrange(r - 1):
            print "*" * c
    elif r == 1:
        print "c" + "." * (empty - 1) + "*" * m
    elif c == 1:
        print "c\n" + ".\n" * (empty - 1) + "*\n" * m,
    elif empty / c >= 2:
        if empty % c >= 2:
            print "c" + "." * (c - 1)
            for i in xrange(empty/c - 1):
                print "." * c
            print "." * (empty % c) + "*" * (c - empty % c)
            for i in xrange(r - empty/c - 1):
                print "*" * c
        elif empty % c == 0:
            print "c" + "." * (c - 1)
            for i in xrange(empty/c - 1):
                print "." * c
            for i in xrange(r - empty/c):
                print "*" * c
        else:
            if empty / c > 2:
                print "c" + "." * (c - 1)
                for i in xrange(empty/c - 2):
                    print "." * c
                print "." * (c-1) + "*"
                print ".." + "*" * (c-2)
            else:
                print "c" + "." * (c - 2) + "*"
                print "." * (c - 1) + "*"
                print "..." + "*" * (c - 3)
            for i in xrange(r - empty/c - 1):
                print "*" * c
    else:
        if empty % 2 == 0:
            print "c" + "." * (empty/2 - 1) + "*" * (c - empty/2)
            print "." * (empty/2) + "*" * (c - empty/2)
            for i in xrange(r - 2):
                print "*" * c
        else:
            width = empty - 3
            print "c" + "." * (width/2 - 1) + "*" * (c - width/2)
            print "." * (width/2) + "*" * (c - width/2)
            print "..." + "*" * (c - 3)
            for i in xrange(r - 3):
                print "*" * c

test_cases = int(raw_input())
for case in xrange(test_cases):
    r, c, m = map(int, raw_input().split())
    print "Case #%d:" % (case+1)
    minesweeper(r, c, m)

