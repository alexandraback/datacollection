#!/usr/bin/python3

from common import *

def paint_req(r, k):
    # how much paint does it take to paint k rings, the innermost with
    # radius r?

    # A ring of inner radius r takes 2r + 1 paint
    # The first ring has inner radius r, the last ring has inner radius
    # r + 2 (k - 1). Thus the average inner radius is r + (k - 1), and the
    # average paint required is 2 (r + (k - 1)) + 1, and the total paint
    # required is given by:
    return k * (2 * (r + (k - 1)) + 1)

def testcase(x):
    r, t = readintegers()
    # we wish to find the largest k such that paint_req(r, k) <= t

    # the answer is in the range [low, high)
    low = 1
    high = 1000000001 # 1 billion plus 1

    while low + 1 < high:
        mid = (low + high) // 2
        pr = paint_req(r, mid)
        if pr > t:
            high = mid
        if pr <= t:
            low = mid

    writeline("Case #%d: %d" % (x, low))

run_tests(testcase)
