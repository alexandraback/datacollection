#!/usr/bin/env python
"""
O((B-A)*|B|)
"""

import sys

def how_many_pairs(n, A, B):
    assert A <= n <= B
    how_many = 0
    seen = set() # 123123123
    n_str = str(n)
    for count in xrange(1, len(n_str)):
        m_str = n_str[-count:] + n_str[:-count]
        assert len(m_str) == len(n_str)
        m = int(m_str)
        if A <= m <= B and \
           m > n and \
           m not in seen:
            how_many += 1
            seen.add(m)
            # print (n, m)
    return how_many

def main():
    lines = sys.stdin.read().splitlines()[1:]
    for index, line in enumerate(lines, start=1):
        A, B = map(int, line.split())
        count = 0
        for n in xrange(A, B):
            if n % 10000 == 0:
                print >>sys.stderr, B-n, '/', B-A
            count += how_many_pairs(n, A, B)
        print 'Case #%d: %d' % (index, count)

if __name__ == '__main__':
    main()
