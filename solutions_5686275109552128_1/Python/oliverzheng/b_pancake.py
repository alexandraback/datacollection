#!/usr/bin/python

import sys, itertools, math

def factors(num):
    sqrt = int(math.floor(math.sqrt(num)))
    return [(level, int(math.ceil(num / float(level + 1))))
            for level in xrange(sqrt)]

if __name__ == '__main__':
    cases = None
    is_counts = True
    for i, line in enumerate(sys.stdin):
        line = line.strip()

        if cases is None:
            cases = int(line)
            continue

        if is_counts:
            is_counts = False
            continue
        else:
            is_counts = True

        pancakes = [int(p) for p in line.split()]
        pancake_factors = [factors(p) for p in pancakes]
        tallest = max(pancakes)
        times_at_levels = (
            sum(
                min(fac[0] for fac in factors if fac[1] <= m)
                for factors in pancake_factors
            ) + m
            for m in xrange(1, tallest + 1)
            if all(
                any(True for factor in factors if factor[1] <= m)
                for factors in pancake_factors
            )
        )

        shortest_time = min(times_at_levels)

        print 'Case #%d: %d' % (i / 2, shortest_time)
        sys.stdout.flush()
