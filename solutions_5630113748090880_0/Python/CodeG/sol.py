#!/usr/bin/python

t = int(raw_input())

for i in range(t):
    heights = [0] * 2500
    val = int(raw_input())
    for j in range(2 * val - 1):
        rows = raw_input().strip().split(' ')
        for height in rows:
            heights[int(height) - 1] += 1
        
    print "Case #" + str(i + 1) + ":",
    for x in range(2500):
        if heights[x] % 2 == 1:
            print str(x + 1),

    print
