__author__ = 'ar'

def solve(people):
    if len(people) == 1:
        return 0

    speeds = {a[1] for a in people}
    if len(speeds) == 1:
        return 0
    # sort people by speeds
    s = sorted(people, key=lambda x: -x[1])
    slow_guy = s[0]
    # print "Slow: %s" % str(slow_guy)
    fast_guy = s[1]
    # print "Fast: %s" % str(fast_guy)
    slow_guy_speed = slow_guy[1]
    fast_guy_speed = fast_guy[1]
    slow_guy_pos = slow_guy[0]
    fast_guy_pos = fast_guy[0]

    dist_from_slow_to_fst = slow_guy_pos - fast_guy_pos
    if dist_from_slow_to_fst <= 0:
        dist_from_slow_to_fst += 360

    # print "Dist from slow to fst: %s" % dist_from_slow_to_fst
    slow_guy_time = slow_guy_speed * (360.0 - slow_guy_pos) / (360.)
    # print "Slow guy time: %s" % slow_guy_time
    distance_covered_by_fast = (360.0 / fast_guy_speed) * slow_guy_time
    # print "Distance covered by fast: %s" % distance_covered_by_fast

    if distance_covered_by_fast > dist_from_slow_to_fst:
        return 1
    return 0

def solve2(people):
    if len(people) == 1:
        return 0

    speeds = {a[1] for a in people}
    if len(speeds) == 1:
        return 0
    # sort people by speeds
    s = sorted(people, key=lambda x: -x[1])
    slow_guy = s[0]
    # print "Slow: %s" % str(slow_guy)
    fast_guy = s[1]
    # print "Fast: %s" % str(fast_guy)
    slow_guy_speed = slow_guy[1]
    fast_guy_speed = fast_guy[1]
    slow_guy_pos = slow_guy[0]
    fast_guy_pos = fast_guy[0]

    dist_to_be_covered_by_fast = 360
    if slow_guy_pos > fast_guy_pos:
        dist_to_be_covered_by_fast += slow_guy_pos - fast_guy_pos
    else:
        dist_to_be_covered_by_fast += 360 - fast_guy_pos
    # print "Dist from slow to fst: %s" % dist_from_slow_to_fst
    slow_guy_time = slow_guy_speed * (360.0 - slow_guy_pos) / (360.)
    # print "Slow guy time: %s" % slow_guy_time
    distance_covered_by_fast = (360.0 / fast_guy_speed) * slow_guy_time
    # print "Distance covered by fast: %s" % distance_covered_by_fast

    if distance_covered_by_fast >= dist_to_be_covered_by_fast:
        return 1
    return 0

if __name__ == "__main__":
    t = int(input())
    for idx in range(0, t):
        N = int(input())
        people = []
        for i in range(0, N):
            s = [int(s) for s in raw_input().split()]
            d_i, h_i, m_i = s[0], s[1], s[2]
            for i in range(0, h_i):
                people.append((d_i, m_i + i))

        assert len(people) <= 2
        res = solve2(people)
        print "Case #%d: %s" % (idx + 1, res)
