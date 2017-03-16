
from math import floor, sqrt

def enumerate_splits(x):
    if x >= 4:
        start = int(floor(sqrt(x)))
        for i in xrange(start, x-1):
            yield [i, x-i]

def can_do_it_in(plates, x, splits):
    if splits >= x:
        return False
    if plates[0] + splits <= x:
        return True

    return any((
        can_do_it_in(sorted(split + plates[1:], reverse=True), x, splits+1)
        for split in enumerate_splits(plates[0])
    ))

def solve(plates):
    plates.sort(reverse=True)
    a, b = 1, 9
    while b-a > 1:
        m = (a+b)//2
        if can_do_it_in(plates, m, 0):
            b = m
        else:
            a = m

    return a if can_do_it_in(plates, a, 0) else b


T = int(raw_input())
for t in range(1, T+1):
    raw_input()
    print "Case #%d: %d" % (
        t,
        solve(map(int, raw_input().split()))
    )
