__author__ = 'deniskrut'

import sys

t = int(sys.stdin.readline())

for i in range(0, t):
    tar_x, tar_y = [int(x) for x in sys.stdin.readline().split()]
    path = ""
    cur_x = 0
    cur_y = 0
    cur_jump = 1
    while cur_x != tar_x:
        cur_jump += 2
        if cur_x < tar_x:
            path += "WE"
            cur_x += 1
        else:
            path += "EW"
            cur_x -= 1
    while cur_y != tar_y:
        if cur_y < tar_y:
            path += "SN"
            cur_y += 1
        else:
            path += "NS"
            cur_y -= 1
    print "Case #" + str(i + 1) + ": " + str(path)