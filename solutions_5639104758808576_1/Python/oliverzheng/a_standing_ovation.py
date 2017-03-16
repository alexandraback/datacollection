#!/usr/bin/python

import sys

cases = None
for i, line in enumerate(sys.stdin):
    line = line.strip()

    if cases is None:
        cases = int(line)
        continue

    (s_max, s_str) = line.split()

    friends_needed = 0
    standing = 0

    for s_i, s in enumerate(s_str):
        s_count = int(s)
        if s_count == 0:
            continue

        if standing < s_i:
            extras_needed = s_i - standing
            friends_needed += extras_needed
            standing += friends_needed

        standing += s_count

    print 'Case #%d: %d' % (i, friends_needed)
