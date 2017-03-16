#!/usr/bin/env python
import sys

def value(boxes, toys):
    score = 0
    if not boxes or not toys:
        return 0
    a, A = boxes[0]
    b, B = toys[0]
    if A == B:
        used = min(a,b)
        score += used
        if used == a:
            score += value(boxes[1:], [(b-used, B)] + toys[1:])
        else:
            score += value([(a-used, A)] + boxes[1:], toys[1:])
    else:
        s1 = value(boxes[1:], toys)
        s2 = value(boxes, toys[1:])
        score += max(s1, s2)
    return score


def solve(n, m, boxes, toys):
    return value(boxes, toys)

if __name__ == '__main__':
    with open(sys.argv[1], 'rU') as fin, open(sys.argv[2], 'w') as fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            print "Case #{0}:".format(case)

            N, M = map(int, fin.readline().split())
            line = map(int, fin.readline().split())
            boxes = []
            for i in xrange(N):
                boxes.append((line[2*i], line[2*i+1]))

            line = map(int, fin.readline().split())
            toys = []
            for i in xrange(M):
                toys.append((line[2*i], line[2*i+1]))

            soln = solve(N, M, boxes, toys)
            print soln
            print >> fout, "Case #{0}: {1}".format(case, soln)
