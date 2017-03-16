#!/usr/bin/env python
from itertools import groupby

test_cases = int(raw_input())

for counter in xrange(1, test_cases+1):
    coded_data = raw_input()
    
    compressed = [k for (k,g) in groupby(coded_data)]
    if compressed[-1] == '+':
        compressed = compressed[:-1]    
        
    print 'Case #%d: %s' % (counter, len(compressed),)