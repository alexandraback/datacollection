#! /usr/bin/env python

import sys

try:
    fin = open(sys.argv[1], "r")
except:
    sys.exit("ERROR: input file.")

fout = open("cookieout.txt", "w")

T = int(fin.readline())

def solve(c, f, x):
    cur_t = x / 2.0
    cur_rate = 2.0 + f
    next_t = c / 2.0
    while next_t + x / cur_rate <= cur_t:
        cur_t = next_t + x / cur_rate
        next_t += c / cur_rate
        cur_rate += f
    return cur_t

for i in range(T):
    arr = map(float, fin.readline().split(' '))
    c = arr[0]
    f = arr[1]
    x = arr[2]
    ans = solve(c, f, x)
    fout.write("Case #" + str(i+1) + ": " + str(ans) + "\n")
