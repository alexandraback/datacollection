#!/usr/bin/python

import sys

MAX = int(sys.argv[1])
print MAX*MAX*MAX
for i in range(1, MAX+1):
    for j in range(1, MAX+1):
        for x in range(1, MAX+1):
            print i, j, x
