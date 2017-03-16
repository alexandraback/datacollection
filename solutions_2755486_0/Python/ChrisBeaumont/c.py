from bisect import bisect_left
from collections import defaultdict

def attacked(segments, heights, l, r, s):
    i0 = bisect_left(segments, l)
    i1 = bisect_left(segments, r)

    #interior points
    assert i0 > 0 and i0 < len(segments)
    assert i1 > 0 and i1 < len(segments)


    #check for success
    result = 0
    assert segments[i0 - 1] < l
    for i in range(i0 - 1, i1 + 1):
        if segments[i] < r and segments[i + 1] > l and heights[i] < s:
            return 1
    assert segments[i] >= r
    return 0


def update_segments(segments, heights, l, r, s):
    #print 'update', l, r, s
    #print segments
    #print heights

    i0 = bisect_left(segments, l)
    i1 = bisect_left(segments, r)

    #interior points
    assert i0 > 0 and i0 < len(segments)
    assert i1 > 0 and i1 < len(segments)


    #update structure
    i1 = bisect_left(segments, r)
    if segments[i1] != r:
        assert segments[i1] > r
        segments.insert(i1, r)
        heights.insert(i1, heights[i1-1])

    if segments[i0] != l:
        assert segments[i0] > l
        segments.insert(i0, l)
        heights.insert(i0, heights[i0-1])


    i0 = bisect_left(segments, l)
    i1 = bisect_left(segments, r)
    assert segments[i0] == l and segments[i1] == r
    for i in range(i0, i1):
        assert segments[i] >= l
        assert segments[i] < r
        heights[i] = max(heights[i], s)

        #print segments
        #print heights


def solve(tribes):
    attacks = []
    for t in tribes:
        d0, nattack, w, e, s, dday, dist, ds = t
        attacks.extend((d0 + dday * i, w + dist * i, e + dist * i, s + ds * i) for i in range(nattack))

    assert len(attacks) == sum(t[1] for t in tribes)

    adict = defaultdict(list)
    for a in attacks:
        adict[a[0]].append(a)
    attacks = adict

    segments = [-1000000000000, 1000000000000]
    heights = [0, 0]

    result = 0
    for day in sorted(attacks.keys()):
        for a in attacks[day]:
            d, l, r, s = a
            if attacked(segments, heights, l, r, s):
                result += 1
        for a in attacks[day]:
            d, l, r, s = a
            update_segments(segments, heights, l, r, s)
        for a in attacks[day]:
            d, l, r, s = a
            update_segments(segments, heights, l, r, s)

    return result


#print solve([[0, 3, 0, 2, 10, 2, 3, -2], [10, 3, 2, 3, 8, 7, 2, 0]])
#print '---'
#print solve([[1, 2, 0, 5, 10, 2, 8, 0],
#             [0, 3, 0, 1, 7, 1, 2, 2],
#             [3, 3, 0, 5, 1, 1, 4, 0]])

import sys
data = open(sys.argv[1] + '.in').readlines()
outfile = open(sys.argv[1] + '.out', 'w')

t = int(data[0].strip())
data = data[1:]

for i in range(1, t+1):
    n = int(data[0].strip())
    tribes = [map(int, d.strip().split()) for d in data[1:1 + n]]
    assert len(tribes) == n
    print tribes
    data = data[n+1:]
    s = "Case #%i: %i\n" % (i, solve(tribes))
    print s
    outfile.write(s)

outfile.close()
