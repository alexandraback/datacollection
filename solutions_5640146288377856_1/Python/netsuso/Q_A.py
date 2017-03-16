#!/usr/bin/python3

import sys
import math

ncases = int(sys.stdin.readline().strip())

for t in range(1, ncases+1):
    values = sys.stdin.readline().split()
    r = int(values[0])
    c = int(values[1])
    w = int(values[2])

    result = r * (w + math.ceil((c-w)/w))

    print("Case #{0}: {1}".format(t, result))

