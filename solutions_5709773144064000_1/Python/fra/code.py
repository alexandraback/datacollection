#!/usr/bin/python

import sys


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        farm_price, rate_add, win_cookies = map(float, data.readline().split())
        cur_rate = 2
        time_spent = 0
        cur_best_time = None
        while True:
            best_time_this_loop = win_cookies / cur_rate + time_spent
            if cur_best_time is None or best_time_this_loop < cur_best_time:
                cur_best_time = best_time_this_loop
            else:
                break  # we get it!
            time_spent += farm_price / cur_rate
            cur_rate += rate_add
        print "Case #%d: %.7f" % (icase + 1, cur_best_time)


if __name__ == "__main__":
    main()
