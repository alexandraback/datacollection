#!/usr/bin/env python

test_cases = int(raw_input())
for counter in xrange(1, test_cases+1):
    entry = int(raw_input())
    current_state = entry
    tries = set()
    digits = set()
    while True:
        tries.add(current_state)
        digits |= set(str(current_state))        
        if len(digits) == 10:
            break
        current_state = current_state + entry
        if current_state in tries:
            current_state = None
            break        

    print 'Case #%d: %s' % (counter, current_state if current_state is not None else 'INSOMNIA')
    counter += 1