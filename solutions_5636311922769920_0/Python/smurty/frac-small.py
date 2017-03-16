#!/usr/bin/env python


T = input()
for i in xrange(1, T+1):
    K, C, S = map(int, raw_input().strip().split())
    print 'Case #{}:'.format(i), ' '.join(map(str, range(1, S+1)))

