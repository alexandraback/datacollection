#!/usr/bin/python
import sys
import math


def solve(farm_cost, farm_speed, target, current_speed, cookies):
    time = 0
    while cookies < target:
        #print "speed: ", current_speed, "cookies:", cookies, "time: ", time, "target:" , target

        #calculate wait for target at current speed
        #time_elapsed = target -cookies / current_speed
        time_for_complete = (target - cookies) / current_speed
        time_not_buy = time + time_for_complete

        if cookies < farm_cost:
            #calculate wait for target buying
            time_for_buy = (farm_cost - cookies) / current_speed
        else:
            time_for_buy = 0

        #calculate buy option
        new_cookies = cookies + current_speed * time_for_buy - farm_cost

        new_speed = current_speed + farm_speed
        time_for_complete = (target - new_cookies) / new_speed
        time_buy = time + time_for_buy + time_for_complete

        if time_buy < time_not_buy:
            time += time_for_buy
            cookies = new_cookies
            current_speed += farm_speed
        else:
            cookies = target
            time = time_not_buy

    return time

def main():
    sys.setrecursionlimit(100000)
    tests = int(sys.stdin.readline())

    for test in xrange(tests):
        parts = sys.stdin.readline().split(" ")
        farm_cost = float(parts[0])
        farm_speed = float(parts[1])
        target = float(parts[2])

        current_speed = 2
        cookies = 0
        r = solve(farm_cost, farm_speed, target, current_speed, cookies)

        print "Case #%d: %0.7f" % (test + 1, r)

main()
