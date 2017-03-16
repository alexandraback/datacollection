#! /usr/bin/env python

from sys import stdin
import sys

ntest = input()

for test in xrange(ntest):
    K, C, S = [int(i) for i in stdin.readline().split()]
    ans = [0]
    level = 0
    for i in xrange(K):
        if level == C:
            ans.append(0)
            level = 0
        ans[-1] = ans[-1] * K + i
        level += 1
    print "Case #{}: {}".format(test + 1, ' '.join(str(i+1) for i in ans) if len(ans) <= S else 'IMPOSSIBLE')

