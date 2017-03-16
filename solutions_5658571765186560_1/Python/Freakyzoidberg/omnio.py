#!/usr/bin/python
for t in range(int(raw_input())):
    x,r,c = map(int, raw_input().split())
    case = 'Case #%d:' % (t + 1)
    if x >= 7:
        print "%s RICHARD" % case
    elif x > r and x > c:
        print "%s RICHARD" % case
    elif r * c % x != 0:
        print "%s RICHARD" % case
    elif (x + 1) / 2 > min(r, c):
        print "%s RICHARD" % case
    elif x in (1, 2, 3):
        print "%s GABRIEL" % case
    elif x == 4:
        if min(r, c) > 2:
            print "%s GABRIEL" % case
        else:
            print "%s RICHARD" % case
    elif x == 5:
        if not(min(r, c) == 3 and max(r, c) == 5):
            print "%s GABRIEL" % case
        else:
            print "%s RICHARD" % case
    elif x == 6:
        if min(r, c) > 3:
            print "%s GABRIEL" % case
        else:
            print "%s RICHARD" % case
    else:
        print "%s GABRIEL" % case

