#! /usr/bin/env python

from collections import defaultdict

T = int(input())

def solve(keys, target, length):
    if len(target) > length:
        return 0.0
    for c in target:
        if c not in keys:
            return 0.0
    slen = len(target)
    for i in range(1, len(target)):
        if target[:-i] == target[i:]:
            slen = i
            break
    worst = (length - len(target)) // slen + 1
    allkey = sum(keys.values())
    
    wp = 1.0 # one word prob
    for c in target:
        wp *= keys[c] / allkey

    cwp = 1.0 # one word concat
    for c in target[-slen:]:
        cwp *= keys[c] / allkey
    if slen == len(target):
        cwp = 0.0
    failp = 1 - keys[target[0]] / allkey

    expected = 0.0
    expexp = {}
    def cnt_exp(remain, canc):
        if remain < slen:
            return 0
        if (remain, canc) in expexp:
            return expexp[(remain, canc)]
        ans = 0
        if canc:
            ans += cwp * (1 + cnt_exp(remain - slen, 1))
            ans += cnt_exp(remain, 0)
        else:
            if remain >= len(target):
                ans += wp * (1 + cnt_exp(remain - len(target), 1))
            ans += failp * cnt_exp(remain - 1, 0)
        expexp[(remain, canc)] = ans
        return ans

    expected = cnt_exp(length, 0)

    return worst - expected
        

for t in range(1, T+1):
    k, l, s = [int(x) for x in input().split()]
    keys = defaultdict(int)
    for c in input():
        keys[c] += 1
    target = input()

    ans = round(solve(keys, target, s), 8)
    print("Case #{}: {}".format(t, ans))
