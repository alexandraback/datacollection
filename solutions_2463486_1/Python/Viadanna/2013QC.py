#!/usr/bin/python

import json
import os

if not os.path.isfile("memo.json"):
    fq, i = [], 0
    while i < 10 ** 7:
        if str(i) == str(i)[::-1]:
            s = i ** 2
            if str(s) == str(s)[::-1]:
                print "Found fair and square %d" % s
                fq.append(s)
        i += 1
    # for i in fq[::-1]:
    #     j = i
    #     while j < 10 ** 100:
    #         j = j ** 2
    #         if j in fq:
    #             break
    #         elif str(j) == str(j)[::-1]:
    #             print "Found fairer and squarer %d" % s
    #             fq.append(j)
    #         else:
    #             print "Found a circular"
    #             break
    with open("memo.json", "w") as f:
        f.write(json.dumps(fq))
else:
    with open("memo.json") as f:
        fq = json.loads(f.read())
    for t in xrange(1, int(raw_input()) + 1):
        a, b = [int(n) for n in raw_input().split()]
        print "Case #%d: %d" % (t,
            len([None for i in fq if i >= a and i <= b]))
