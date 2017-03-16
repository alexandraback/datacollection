#!/usr/bin/env python
import sys
import heapq

BIG = 9999999

T = int(raw_input())
for t in range(T):
    n = int(raw_input())
    s = [ map(int, raw_input().split()) for i in xrange(n) ]
    s.sort(key = lambda x: x[1], reverse=True)
    # print n, s

    h = []
    for i in xrange(len(s)):
        heapq.heappush(h, (s[i][1], i))

    # print "heap: ", h


    res = 0
    star = 0
    cont = True
    while cont:
        cont = False

        # grab two stars
        while h and h[0][0] <= star:
            cont = True
            if s[h[0][1]][0] < BIG:
                star += 2
                s[h[0][1]][0] = BIG
                s[h[0][1]][1] = BIG
            else:
                star += 1
                s[h[0][1]][1] = BIG
            res += 1
            # print "two star: ", h[0][1]
            heapq.heappop(h)

        for i in xrange(len(s)):
            if s[i][0] <= star:
                res += 1
                # print "one star: ", i
                cont = True
                s[i][0] = BIG
                star += 1
                break

    if h:
        res = "Too Bad"

    print "Case #%d: %s" % (t+1, str(res))
