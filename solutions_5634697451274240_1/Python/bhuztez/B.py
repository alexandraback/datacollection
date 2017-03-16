#!/usr/bin/env python2

import re

def solve():
    line = raw_input().strip()
    print len(re.findall(r'\++|\-+',line.rstrip('+')))

T = int(raw_input())

for i in xrange(T):
    print 'Case #%d:' % (i+1),
    solve()
