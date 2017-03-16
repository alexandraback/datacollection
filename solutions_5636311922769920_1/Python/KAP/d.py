#!/usr/bin/python3
ntests = int(input())
for test in range(ntests):
    print('Case #%d: ' % (test+1), end='')
    k, c, s = map(int, input().split())
    if c*s < k:
        print('IMPOSSIBLE')
        continue
    pos = 0
    nn = 0
    for i in range(k):
        if (nn == c):
            print(pos+1, end=' ')
            pos = 0
            nn = 0
        pos = pos * k + i
        nn += 1
    if (nn != 0):
        print(pos+1, end=' ')
    print('')