#!/usr/bin/python

for t in range(int(input())):
    raw_input()
    plates = list(map(int, raw_input().split()))
    answer = max(plates)
    Z = 0
    while Z + 2 < answer:
        res = 0
        for x in plates:
            res += (x - 1) / (Z + 2)
        pos = res + (Z + 2)
        answer = min(answer, pos)
        Z += 1
    print('Case #%d: %s' % (t + 1, answer))
