#!/usr/bin/env python

test_cases = int(raw_input())
for counter in xrange(1, test_cases+1):
    entry = int(raw_input())    
    
    current_state = entry
    
    if entry != 0:
        digits = set()
        while True:
            digits |= set('%d' % (current_state,))        
            if len(digits) == 10:
                break
            current_state = current_state + entry
    
    print 'Case #%d: %s' % (counter, '%d' % (current_state,) if current_state != 0 else 'INSOMNIA')