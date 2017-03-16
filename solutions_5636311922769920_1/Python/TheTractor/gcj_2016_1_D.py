#!/usr/bin/env python

test_cases = int(raw_input())

def to_base(int_seq, base):
    result = 0
    for e in int_seq:
        result *= base
        result += e
    return result

for counter in xrange(1, test_cases+1):
    (k, c, s) = (int(x) for x in raw_input().split(' '))
    
    # We look at base-k representation of the tile numbers; the digits of these
    # give the path of expanded nodes from the original pattern to the expanded one.
    # Condition: each plate checked checks a disjunction of (up to) 
    # c predicates of the form "i-th original tile was G"
    # Thus a hard bound on s is s * c >= k, or alternatively, s >= k / c,
    # or, in integer form, s >= ceil(k/c)
    
    result = 'IMPOSSIBLE'
    if s >= (k + (c-1)) // c:
        test_paths = list(range(0, k))
        test_paths_legnth_remainder = len(test_paths) % c
        if 0 != test_paths_legnth_remainder:
            test_paths += [0,] * (c - test_paths_legnth_remainder)
        # 1 is because tiles are indexed 1, 2, ...
        test_numbers = [1 + to_base(test_paths[c * i: c * (i+1)], k) for i in xrange(len(test_paths)//c)]
        result = ' '.join('%d' % (k,) for k in test_numbers)
    
    print 'Case #%d: %s' % (counter, result,)