#!/usr/bin/env python3
import sys

import itertools


def log(*a, **kw):
    print(*a,file=sys.stderr, **kw)


def valid(train):
    current = None
    visited = set()
    for x in train:
        if current is None:
            current = x
            visited.add(x)
        else:
            if x != current:
                if x in visited:
                    #log(x, 'fail')
                    return False
                else:
                    current = x
                    visited.add(x)
        #log(x, end="")
    #log()
    return True


def compact(s):
    r = ''
    last = None
    for x in s:
        if last != x:
            last = x
            r += x
    return r


def main(t):
    N = int(input())
    trains = [x for x in input().split()]
    log('input', t, trains)
    trains = [compact(x) for x in trains]
    log(trains)
    r = 0
    for train in itertools.permutations(trains):
        if valid(''.join(train)):
            r += 1
    r = r % 1000000007
    print("Case #%s: %s" % (t, r))


T = int(input())
for t in range(T):
    main(t+1)
