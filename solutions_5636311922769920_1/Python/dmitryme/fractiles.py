#!/usr/bin/python
import sys

fl = open(sys.argv[1])

cases = int(fl.readline())

for case_number in range(1, cases + 1):
    K, C, S = map(int, fl.readline().split())

    if S * C < K:
        print 'Case #%s: IMPOSSIBLE' % case_number
        continue

    ans = []
    i = 0

    while i < K:
        n = 0

        for j in range(0, C):
            n *= K
            if i < K:
                n += i
                i += 1

        ans.append(n + 1)

    print 'Case #%s: %s' % (case_number, ' '.join(map(str, ans)))
