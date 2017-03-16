#!/usr/bin/python

import sys
import logging

logging.basicConfig(stream=sys.stderr, level=logging.DEBUG)

def solve(b, m):
    logging.debug('b %d, m %d', b, m)
    max_paths = 2 ** (b-2)
    logging.debug('max paths: %d', max_paths)
    if m > max_paths:
        return False

    graph = []
    for r in range(b):
        row = [0 for n in range(1 + r)] + [1 for n in range(b - r - 1)]
        graph.append(row)

    i = b-3
    logging.debug('starting with %d', i)
    while max_paths > m and i > -2:
        if max_paths - 2 ** i >= m:
            logging.debug('blanking %d to lose %d', b-1-2, 2**i)
            graph[0][b-i-2] = 0
            max_paths -= 2**i if i > -1 else 1
        i -= 1

    return graph

first = True
n = 0
for line in sys.stdin:
    if first:
        first = False
    else:
        n = n + 1
        b, m = map(int, line.split(' '))
        ans = solve(b, m)
        if ans:
            print "Case #%d: POSSIBLE" % n
            for r in ans:
                print ''.join(map(str, r))
        else:
            print "Case #%d: IMPOSSIBLE" % n
