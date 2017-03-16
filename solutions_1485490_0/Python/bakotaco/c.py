#!/usr/bin/env python

from sys import stdin, stderr

def debug(args):
    print >> stderr, args

for tc in xrange(1, int(stdin.readline()) + 1):
    n, m = [int(w) for w in stdin.readline().split()]
    a = [int(w) for w in stdin.readline().split()]
    b = [int(w) for w in stdin.readline().split()]
    candidates = []
    candidates.append([0, 0, 0, 0, 0])
    maximum = 0
    while candidates:
        candidate = candidates.pop()
        if candidate[0] >= n:
            maximum = max(maximum, candidate[4])
        elif candidate[2] >= m:
            maximum = max(maximum, candidate[4])
        else:
            if a[2 * candidate[0] + 1] == b[2 * candidate[2] + 1]:
                left_a = a[2 * candidate[0]] - candidate[1]
                left_b = b[2 * candidate[2]] - candidate[3]
                used = min(left_a, left_b)
                new_candidate = candidate[:]
                new_candidate[1] += used
                new_candidate[3] += used
                if new_candidate[1] == a[2 * candidate[0]]:
                    new_candidate[0] += 1
                    new_candidate[1] = 0
                if new_candidate[3] == b[2 * candidate[2]]:
                    new_candidate[2] += 1
                    new_candidate[3] = 0
                new_candidate[4] += used
                candidates.append(new_candidate)
            else:
                new_candidate = candidate[:]
                new_candidate[0] += 1
                new_candidate[1] = 0
                candidates.append(new_candidate)
                new_candidate = candidate[:]
                new_candidate[2] += 1
                new_candidate[3] = 0
                candidates.append(new_candidate)
    print 'Case #%d: %s' % (tc, maximum)
