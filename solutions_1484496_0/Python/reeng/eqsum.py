#!/usr/bin/env python
import sys


def log(fmt, *args):
    sys.stderr.write((fmt + '\n') % args)

def read_int():
    return int(raw_input())

def read_ints():
    return [int(s) for s in raw_input().split()]


def do_case():
    data = read_ints()
    N, S = data[0], data[1:]
    assert N == len(S)
    
    sums = dict((n, set((n,))) for n in S)
    new_sums = dict()

    for _ in xrange(N):
        for sum1, subset1 in sums.iteritems():
            for sum2, subset2 in sums.iteritems():
                if sum1 == sum2:
                    continue
                new_subset = subset1.union(subset2)
                new_sum = sum(new_subset)
                if new_sum in sums:
                    old_subset = sums[new_sum]
                    if old_subset != new_subset:
                        print ' '.join(str(n) for n in new_subset)
                        print ' '.join(str(n) for n in old_subset)
                        return
                new_sums[new_sum] = new_subset
        sums.update(new_sums)
    
    print 'Impossible'


for case in xrange(read_int()):
    print 'Case #%d:' % (case + 1)
    do_case()
