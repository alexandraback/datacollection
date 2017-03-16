#!/usr/bin/env python
# encoding: utf-8

T = int(raw_input())
for i in xrange(1, T+1):
    R, C, W = map(int, raw_input().split())
    min_moves = 0
    if W == 1:
        min_moves = R * C
    else:
        occupancy_moves_per_row = C // W
        min_moves = occupancy_moves_per_row * R
        if C % W == 0:
            min_moves += W - 1
        else:
            min_moves += W
    print "Case #" + str(i) + ": " + str(min_moves)
