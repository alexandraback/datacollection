#!/usr/bin/python
import sys
import math


def solve(farm_cost, farm_speed, target, current_speed, cookies, time, max_time):
    #print "speed: ", current_speed, "cookies:", cookies, "time: ", time, "max_time", max_time
    if max_time is not None and time >= max_time:
        return None

    if cookies >= target:
        return time

    #calculate wait for target at current speed
    #time_elapsed = target -cookies / current_speed
    time_elapsed = (target - cookies) / current_speed
    time_not_buy = time + time_elapsed
    if max_time is not None and time_not_buy >= max_time:
        return None

    if cookies < farm_cost:
        #calculate wait for target buying
        time_elapsed = (farm_cost - cookies) / current_speed
        cookies += current_speed * time_elapsed

        time_buy = solve(farm_cost, farm_speed, target, current_speed + farm_speed, cookies - farm_cost, time + time_elapsed, time_not_buy)

    else:
        #cookies >= farm_cost, no need to wait for buying
        time_buy = solve(farm_cost, farm_speed, target, current_speed + farm_speed, cookies - farm_cost, time, time_not_buy)

    if time_buy is not None:
        result = min(time_buy, time_not_buy)
    else:
        result = time_not_buy
    return result

def main():
    sys.setrecursionlimit(1000000)
    tests = int(sys.stdin.readline())

    for test in xrange(tests):
        parts = sys.stdin.readline().split(" ")
        farm_cost = float(parts[0])
        farm_speed = float(parts[1])
        target = float(parts[2])

        current_speed = 2
        cookies = 0
        time = 0
        max_time = None
        r = solve(farm_cost, farm_speed, target, current_speed, cookies, time, max_time)

        print "Case #%d: %0.7f" % (test + 1, r)

main()
