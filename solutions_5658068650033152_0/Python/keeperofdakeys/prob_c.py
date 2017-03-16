#!/usr/bin/env python

def get_internal(stones, x_coord, y_coord):
    min_coord = min(x_coord, y_coord)
    max_coord = max(x_coord, y_coord)
    num = stones
    interval = stones/2
    intersections = set()
    intersections.add(0)
    for spare in xrange(0, 5):
        working = stones - spare
        if working < 4 or working % 2 != 0:
            continue
        half_work = working / 2
        for x in xrange(1, half_work):
            y = half_work - x
            result = x * y
            if result not in intersections and min(x,y) + 2 <= min_coord and max(x,y) + 2 <= max_coord:
                intersections.add(result)
                #print stones, x, y, working, max_num, result
    return intersections

count = int(raw_input())
for x in xrange(1,count+1):
    nums = raw_input().split(" ")
    x_coord = int(nums[0])
    y_coord = int(nums[1])
    points = int(nums[2])
    min_stones = points + 1
    for y in xrange(1, points+1):
        for z in get_internal(y, x_coord, y_coord):
            intersections = y + z
            if points == intersections and y < min_stones:
                min_stones = y
    print ("Case #" + str(x) + ": " + str(min_stones))
