import math

cases = int(raw_input())
for case in xrange(cases):
    r, t = [int(x) for x in raw_input().split()]

    used = 0
    ring = 0
    while True:
        needed = 2*r + 4*ring + 1
        # print needed, t, used
        if needed > (t - used):
            result = ring
            break

        used += needed
        ring += 1
        # print ring, needed, used


    print "Case #{}: {}".format(case+1, result)

