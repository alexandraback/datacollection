# -*- coding: utf-8 -*- 
import os, sys, copy, time, itertools

def solve(line):
    nums = map(int, line.split())
    nums.pop(0)
    indexes = xrange(20)
    sums = {}

    for i in indexes:
        iter = itertools.combinations(indexes, i + 1)
        while True:
            try:
                idxes = iter.next()
                p1 = [nums[idx] for idx in idxes]
                s = sum(p1)
                if sums.has_key(s):
                    p2 = [nums[idx] for idx in sums[s]]
                    return [p2, p1]
                else:
                    sums[s] = idxes
            except StopIteration:
                break

    return None   

lines = sys.stdin.read().split('\n')
lines.pop()
lines.pop(0)

case = 0
while lines:
    case += 1
    line = lines.pop(0)

    result = solve(line)

    if result:
        print 'Case #%d:' % (case)
        for pair in result:
            print ' '.join(map(str, pair))
    else:
        print 'Case #%d: Impossible' % (case)
