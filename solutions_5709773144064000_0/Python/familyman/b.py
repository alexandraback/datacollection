# insight:
#  - if you should buy a new farm, buy it as ASAP as possible

import sys

_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())
D = lambda: float(_input.pop())


def solve_one():
    C, F, X = D(), D(), D()

    def earnings_per_sec(num_farms):
        return 2.0 + num_farms * F

    def time_to_earn(num_cookies, num_farms):
        """
        Time to earn num_cookies cookies, given num_farms farms.
        """
        return num_cookies / earnings_per_sec(num_farms)

    best_end_time = 1E42

    cur_time = 0.0
    cur_cookies = 0
    cur_farms = 0

    while cur_time <= best_end_time:
        cookies_rem = X - cur_cookies
        cur_res = cur_time + time_to_earn(cookies_rem, cur_farms)
        best_end_time = min(best_end_time, cur_res)

        # can buy farm?
        if cur_cookies >= C:
            cur_cookies -= C
            cur_farms += 1
        else:
            # step forward till we can buy a farm
            t = time_to_earn(C, cur_farms)
            cur_time += t
            cur_cookies += t * earnings_per_sec(cur_farms)
            cur_cookies += 1E-13
            if not cur_cookies >= C:
                print 'ARGH!'
                assert False

    return best_end_time


for i in range(1, I()+1):
    print 'Case #%d: %.7f' % (i, solve_one(),)
