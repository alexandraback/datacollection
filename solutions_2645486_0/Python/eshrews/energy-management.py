#!/usr/bin/python

import fileinput
import heapq

case = 0
E, R, N = 0, 0, 0
for linenum, line in enumerate(fileinput.input()):
    if linenum == 0:
        cases = int(line)
        continue

    l = [int(x) for x in line.split()]
    result = 0
    if(linenum % 2 == 1):
        E = l[0]
        R = l[1]
        N = l[2]
        continue
    else:
        case += 1
        dist = [len(l)] * len(l)
        e = E

        h = []
        for i, vi in enumerate(l):
            while(h and h[0][0] < vi):
                oldi = h[0][1]
                dist[oldi] = i - oldi
                heapq.heappop(h)
            heapq.heappush(h, (vi,i))

        for i in xrange(len(l)):
            vi = l[i]
            disti = dist[i]
            if disti == len(l):
                use = e
            else:
                use = max(e + (R*disti) - E, 0)
                use = min(e, use)
                
            e -= use
            e += R
            result += (vi * use)
            

    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
