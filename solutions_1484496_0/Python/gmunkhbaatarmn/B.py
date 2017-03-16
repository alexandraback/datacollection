#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w+')

def subsetsum(nums, tgt):
    sums = {}
    for n in nums[::2]:
        for k,v in sums.items() + [(0,[])]:
            newsum = k + n
            if newsum not in sums:
                sums[newsum] = v + [n]
                if newsum == tgt:
                    return sums[tgt]

    difs = {tgt:[]}
    for n in nums[1::2]:
        for k,v in difs.items():
            newdif = k - n
            if newdif not in difs:
                difs[newdif] = v + [n]
                if newdif in sums:
                    return sums[newdif] + difs[newdif]

    return []


def calc(nums):
    pass

from copy import deepcopy

T = input()
for t_case in range(1, T+1):
    nums = [int(num) for num in raw_input().split(' ')][1:]
    # print nums
    print 'Case #%s:' % t_case
    dic = {}
    sums = [0]

    for i in nums:
        sums1 = deepcopy(sums)

        for sm in sums:
            if not sm+i in dic:
                dic[sm+i] = 1
                sums1.append(sm+i)
        sums = deepcopy(sums1)

    sums = sums[1:]

    for i in sums:
        ans = subsetsum(nums, i)
        if len(ans) > 0:
            ans2 = subsetsum(list(set(nums) - set(ans)), i)
            if len(ans2) > 0:
                for a in ans:
                    print a,
                print
                for b in ans2:
                    print b,
                print
                break
