#!/bin/python
from collections import deque
T = int(input())
for i in range(T):
    S = input()
    sMax = max(list(S))
    o = deque()
    o.append(S[0])
    for j in S[1:]:
        if j >= o[0]:
            o.appendleft(j)
        else:
            o.append(j)
    o = ''.join(o)
    print('Case #{}: {}'.format(i+1, o))
