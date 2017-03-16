import random
from copy import deepcopy
# f = open('input.txt')
f = open('/home/aaronm/Desktop/C-small-attempt2.in')
# f = open('/home/aaronm/Desktop/B-large.in')
t = int(f.readline())

def get_sets(nums):
    segments = []
    straight_segments = []
    reversible_segments = []
    for i in range(len(nums)):
        segment = []
        person = i
        while True:
            segment.append(person)
            bff = nums[person] - 1
            if bff in segment:
                if segment[0] == bff:
                    #it's a loop! happy
                    segments.append(segment)
                    # straight_segments.append(segment)
                elif segment[-2] == bff:
                    # it's reversible
                    reversible_segments.append(segment[:-1])
                    straight_segments.append(segment)
                    # del segment[-1]
                else:
                    del segment[-1]
                    straight_segments.append(segment)
                break

            # prepare and repeat
            person = bff

        # segments.append(segment)

    # print segments
    # print reversible_segments

    if reversible_segments:
        new_segments = []
        for rs in reversible_segments:
            last_num = rs[-1]
            for s in straight_segments:
                if s[-1] == last_num:
                    joined = set(rs + s)
                    if len(joined) == len(rs) + len(s) - 1:
                        new_segments.append(rs[:-1] + list(reversed(s)))
        # print "new segments"
        # print new_segments
        longest = 0
        remaining_segments = new_segments
        while remaining_segments:
            s = remaining_segments.pop()
            for j in new_segments:
                joined = set(s + j)
                if len(joined) == len(s) + len(j):
                    # print 'victory!'
                    # print s,j
                    remaining_segments.append(s+j)

            if len(s) > longest:
                longest = len(s)
        return longest

    longest = 0
    for s in segments:
        if len(s) > longest:
            longest = len(s)

    return longest

for case in range(t):
    n = int(f.readline())

    nums = [int(i) for i in f.readline().split()]
    # print nums

    longest = get_sets(nums)
    # print longest
    # print
    print "Case #%s: %s" % (case+1, longest)