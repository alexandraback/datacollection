#!/usr/bin/env python
from math import ceil
def solve():
    line = raw_input()
    k,l,s = [int(x) for x in line.split()]
    keyboards = raw_input()
    target = raw_input()
    keyboards = keyboards[:k]
    target = target[:l]

    p = {}
    for c in keyboards:
        if c in p:
            p[c] += 1
        else:
            p[c] = 1
    for c in p:
        p[c] = float(p[c]) / float(k)

    ans = 1.0
    for t in target:
        if t in p:
            ans *= p[t]
        else:
            ans = 0
            break
    if ans == 0:
        return ans
    # ans = (s - l + 1) * ans

    total = 1
    longest = target
    i = 0
    while len(longest) < s:
        i += 1
        if longest[i:] == target[:len(target) - i] or (i >= len(longest) and i < s):
            longest += target[len(longest) - i:]
            total += 1
    if len(longest) > s:
        total -= 1

    # print ans, total, longest
    return total * (1 - ans)

case_num = input()
for case in range(1, case_num + 1):
    print("Case #%i: %.7f" % (case, solve()))

