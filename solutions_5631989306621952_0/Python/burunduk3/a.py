#!/usr/bin/env python3

tn = int (input ())
for t in range (1, tn + 1):
    s = input ()
    ans = ''
    for c in s:
        if c + ans > ans + c:
            ans = c + ans
        else:
            ans = ans + c
    print ("Case #%d: %s" % (t, ans))

