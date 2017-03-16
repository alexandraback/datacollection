#!/usr/bin/env python
test_cases = int(raw_input())

MIN_BASE=2
MAX_BASE=10

for counter in xrange(1, test_cases+1):
    print 'Case #%d:' % (counter,)
    (n,j) = [int(k) for k in raw_input().split(' ')]
    
    assert n > 1
    trial = 1 + (1 << (n-1))
    
    while j > 0:
        bin_repr = bin(trial)[2:]
        witnesses = []
        
        for base in xrange(MIN_BASE,MAX_BASE+1):
            base_integer = int(bin_repr, base)            
            break_outer = True # failure
            for divisor in (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47):
                if divisor < base_integer and 0 == base_integer % divisor:
                    witnesses.append(divisor)
                    break_outer = False
                    break

            if break_outer:
                break
        
        if MAX_BASE + 1 - MIN_BASE == len(witnesses):
            print('%s ' % (bin_repr,) + ' '.join('%d' % (w,) for w in witnesses))
            j -= 1
        
        trial += 2 # keep odd
    