#!/usr/bin/env python
import math
import sys
def solve():
    line = raw_input()
    n = int(line)
    sys.stderr.write(line + "\n")

    leap = {}
    last = 1
    for i in xrange(2, n+1):
        last += 1
        if i in leap:
            leap[i] = min(leap[i], last)
            last = leap[i]
        ri = int(str(i)[::-1])
        if ri <= n and ri > i:
            if ri in leap:
                leap[ri] = min(leap[ri], last + 1)
            else:
                leap[ri] = last + 1

    return last

case_num = input()
for case in range(1, case_num + 1):
    ans = solve()
    print("Case #%i: %i" % (case, ans))
