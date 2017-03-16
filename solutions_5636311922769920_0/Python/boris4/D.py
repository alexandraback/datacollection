#!/usr/bin/python
import sys

T = int(sys.stdin.readline().strip())

for testId in range(1, T + 1):
    line = sys.stdin.readline().strip().split()
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])

    sys.stdout.write('Case #%s:' % testId)
    for i in range(K):
        sys.stdout.write(' %s' % (i + 1))
    sys.stdout.write('\n')
