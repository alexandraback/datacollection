#!/usr/bin/env python

import sys

def solve(totals, p, surprising):
    """
    1) [non-surpising tripple] can have max(t) >= p iff
       3p-2 <= total(t)
    2) [surprising tripple] can have max(t) >= p iff
       3p-4 <= total(t) <= 3p-2
       and t >= 2
    """
    p_or_more = 0
    for total in totals:
        # non-surprising?
        if 3*p-2 <= total:
            p_or_more += 1
        elif surprising > 0 and (max(2, 3*p-4) <= total <= 3*p-2):
            # doesn't matter which of the surprising we choose to upgrade
            surprising -= 1
            p_or_more += 1
    return p_or_more

def main():
    lines = sys.stdin.readlines()[1:]
    for index, line in enumerate(lines, start=1):
        numbers = map(int, line.split())
        _, surprising, p = numbers[:3]
        p_or_more = solve(numbers[3:], p, surprising)
        print 'Case #%d: %d' % (index, p_or_more)

if __name__ == '__main__':
    main()
