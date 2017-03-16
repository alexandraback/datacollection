#)!/usr/bin/python3
# -*- coding: utf-8 -*-
# †
from collections import Counter
from itertools import chain
flatten = chain.from_iterable

t = int(input())
for case in range(t):
    n = int(input())
    mat = flatten([list(map(int, input().split())) for _ in range(2*n-1)])

    cnt = Counter(mat)

    res = []
    for k, v in cnt.items():
        if v & 1:
            res.append(k)
    print('Case #{}: {}'.format(case+1, ' '.join(map(str, sorted(res)))))
