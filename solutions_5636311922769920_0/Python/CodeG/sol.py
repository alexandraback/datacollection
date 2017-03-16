#!/usr/bin/python

t = int(raw_input())

for i in range(t):
    vals = raw_input().split(" ")
    k, c, s = (int(vals[0]), int(vals[1]), int(vals[2]))
    print "Case #" + str(i + 1) + ":",
    if s < k - c + 1:
        print "IMPOSSIBLE"
    else:
        print " ".join([str(x) for x in range(1, s + 1)])        
