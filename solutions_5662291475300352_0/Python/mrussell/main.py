import fileinput 
import math
from functools import reduce
import sys

input = fileinput.input()

def first_meet(my_speed, his_speed, his_start):
    if his_speed > my_speed:
        catch_up_by = 360 - his_start
        t = float(catch_up_by) / (his_speed - my_speed)
        position = my_speed * t
        return (t, position)
    elif my_speed > his_speed:
        t = float(his_start) / (my_speed - his_speed)
        position = my_speed * t
        return (t, position)
    else: assert(False)

def num_meeting_points(my_speed, his_speed, distance): # assumes we start at the same place
    if my_speed > his_speed: return 1
    else:
        t = float(distance) / my_speed
        return int(math.floor(his_speed * t / distance))

def num_meets(my_speed, his_speed, his_start):
    if my_speed == his_speed: return 0
    else:
        (_t, first_meet_position) = first_meet(my_speed, his_speed, his_start)
        print "first meet pos: %f" % first_meet_position
        if first_meet_position > 360: return 0
        else: 
            distance_left = 360 - first_meet_position
            return num_meeting_points(my_speed, his_speed, distance_left)

# def test(my_speed, his_speed, his_start):        
#     print "num meets (me = %f, him = %d, his_start = %d): %d" % (my_speed, his_speed, his_start, num_meets(my_speed, his_speed, his_start))

# test(14, 5, 120)
# test(5, 14, 120)
# test(15, 14, 120)

def speeds_to_try(his_speed, his_start, min_speed, max_speed):
    i = 360
    speeds = []
    speed = his_speed * 360. / (i - his_start) + 10 * sys.float_info.epsilon
    while speed < max_speed and speed > min_speed:
        speeds.append(speed)
        i += 360
        # add
        speed = his_speed * 360. / (i - his_start) + 10 * sys.float_info.epsilon
    return speeds

def num_collisions(my_speed, hikers):
    return sum([ num_meets(my_speed, his_speed, his_start) for (his_start, his_speed) in hikers])

def reduce_hikers(hikers, f):
    (_, init) = hikers[0]
    for (_, speed) in hikers:
        init = f(init, speed)
    return init

def min_num_collisions(hikers):
    print(hikers)
    min_speed = reduce_hikers(hikers, min)
    max_speed = reduce_hikers(hikers, max)
    print "max speed: %f" % max_speed
    sys.stdout.flush()
    speeds = [min_speed, max_speed]
    for (his_start, his_speed) in hikers:
        speeds = speeds + speeds_to_try(his_speed, his_start, min_speed, max_speed)
    print "trying speeds: %s" % speeds
    return reduce(lambda x, y: min(x, y), [ num_collisions(my_speed, hikers) for my_speed in speeds])

def do_case(case_num):
    num_groups = int(next(input))
    hikers = []
    for g in range(num_groups):
        start_pos, num_hikers, max_speed = [int(s) for s in next(input).rstrip().split(' ')]
        for j in range(num_hikers):
            revolution_time = max_speed + j
            speed = 360. / revolution_time
            hikers.append((start_pos, speed))
    print "hikers: %s" % hikers
    print "num collisions if i went one: %d" % num_collisions(360., hikers)
    print "num collisions if i went 30: %d" % num_collisions(30., hikers)
    answer = min_num_collisions(hikers)
    print "Case #%d: %d" % (case_num, answer)
        
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

