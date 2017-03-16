#!/usr/bin/env python

vovels = set(['a', 'e', 'i', 'o', 'u'])

def intline(): return map(int, raw_input().split())

N, = intline()

for caseNum in xrange(N):
    name, n = raw_input().split()
    n = int(n)
    matchingBorders = set()

    nonVovelLen = 0

    for i in xrange(len(name)):
        if name[i] not in vovels:       nonVovelLen += 1
        else:                           nonVovelLen  = 0

        if nonVovelLen >= n:
            for start in xrange(i-n+1, -1, -1):
                for end in xrange(i+1, len(name)+1):
                    # print '{0} -> {1}'.format(start, 0)
                    # string = name[start:end]
                    if (start, end) not in matchingBorders:
                        matchingBorders.add((start, end))

    # print matchingBorders

    answer = len(matchingBorders)
    print 'Case #{0}: {1}'.format(caseNum+1, answer)