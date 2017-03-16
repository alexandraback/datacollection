
from fractions import Fraction

def intersect(a_c, a_m, b_c, b_m):
    x = Fraction(b_c - a_c, a_m - b_m)
    y = a_m * x + a_c
    return (x, y)

def crosses_twice(a_start, a_time, b_start, b_time):
    a_speed = Fraction(360, a_time)
    b_speed = Fraction(360, b_time)
    # Does b cross a's first segment?
    x, y = intersect(a_start, a_speed, b_start, b_speed)
    if b_start <= y and y <= 360:
        # Yes it does, check second segment
        x, y = intersect(a_start - 360, a_speed, b_start, b_speed)
        if b_start <= y and y <= 360:
            return True
    return False

def triangle(a_start, a_time, b_start, b_time):
    a_speed = Fraction(360, a_time)
    b_speed = Fraction(360, b_time)
    x, y = intersect(a_start - 360, a_speed, b_start, b_speed)
    if 0 <= y and y <= 360:
        return True

def solve(a_start, a_time, b_start, b_time):
    try:
        if triangle(a_start, a_time, b_start, b_time) or triangle(b_start, b_time, a_start, a_time):
            return 1
        return 0
    except:
        # They never intersect
        return 0

if __name__ == "__main__":
    case_count = int(raw_input())
    for case_num in xrange(1, case_count + 1):
        group_count = int(raw_input())
        hikers = []
        for group_num in xrange(group_count):
            parts = [int(i) for i in raw_input().split()]
            position = parts[0]
            hiker_count = parts[1]
            hiker_time = parts[2]
            for hiker in xrange(hiker_count):
                hikers += [(position, hiker_time)]
                hiker_time += 1
        solution = 0
        if len(hikers) == 2:
            solution = solve(hikers[0][0], hikers[0][1], hikers[1][0], hikers[1][1])
        print "Case #%s: %s" % (case_num, solution)
