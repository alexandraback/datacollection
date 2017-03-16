#!/usr/bin/env pyhotn

import itertools

N = input()

for n in range(N):
    w = input()
    lines = [raw_input().split() for i in range(w)]

    fi = list(set(map(lambda x: x[0], lines)))
    se = list(set(map(lambda x: x[1], lines)))

    for i in range(1, w + 1):
        for act in itertools.combinations(range(w), i):
            p, q = fi[:], se[:]
            for a in act:
                if lines[a][0] in p:
                    p.remove(lines[a][0])
                if lines[a][1] in q:
                    q.remove(lines[a][1])
            if len(p) == 0 and len(q) == 0:
                print 'Case #%d: %d' % (n + 1, w - i)
                break
        else:
            continue
        break
