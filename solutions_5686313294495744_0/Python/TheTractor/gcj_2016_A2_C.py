#!/usr/bin/env python

test_cases = int(raw_input())

def calculate_set_size(x):
    A_set = set()
    B_set = set()
    
    for (a,b) in x:
        A_set.add(a)
        B_set.add(b)
        
    return len(A_set), len(B_set)    
    
for counter in xrange(1, test_cases+1):
    length = int(raw_input())
    
    inputs = []

    for ctr2 in xrange(length):
        inputs.append(raw_input().split())
        
    (A_size, B_size) = calculate_set_size(inputs)
        
    m = length
    for k in xrange((1<<length)-1):
        s = []
        for u in inputs:
            if k & 1:
                s.append(u)
            k >>= 1
        if calculate_set_size(s) == (A_size, B_size):
            m = min(m, len(s))
            
    print 'Case #%d: %d' % (counter, length - m,)