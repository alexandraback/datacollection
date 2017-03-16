#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):

    N = readint()
    num_dict = {}
    for i in range(2*N - 1):
        these_nums = readarray(int)
        for num in these_nums:
            if not (num in num_dict):
                num_dict[num] = 0
            num_dict[num] += 1

    res = []
    for num in num_dict.keys():
        if num_dict[num] % 2 == 1:
            res.append(num)

    res.sort()
    res = map(str, res)


    print 'Case #%i:'%(_t+1), ' '.join(res)
    sys.stdout.flush()
