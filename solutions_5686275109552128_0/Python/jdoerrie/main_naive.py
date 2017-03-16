#!/usr/bin/env python3

import queue
import copy
from collections import Counter

mem = {}
def best(parts):
    if parts in mem:
        return mem[parts]

    last = parts[-1]
    if last < 4:
        mem[parts] = last
        return last

    wait = tuple([part - 1 for part in parts if part > 1])
    split = list(parts)
    last = split.pop()
    split += [last // 2, (last + 1) // 2]
    split = tuple(sorted(split))

    res = 1 + min(best(wait), best(split))
    mem[parts] = res
    return res

# def num_min(cnt):
#     res = 0
#     while True:
#         buckets = Counter([x // 2 for x in cnt.elements()])

#         b = max(buckets.elements())
#         if buckets[b] < b:
#             if cnt[2*b] != 0:
#                 num = cnt[2*b]
#                 cnt[2*b] -= num
#                 cnt[b] += num
#             else:
#                 num = cnt[2*b+1]
#                 cnt[2*b+1] -= num
#                 cnt[b] += num
#                 cnt[b+1] += num
#             res += num
#         else:
#             return res + max(cnt.elements())


def testcase():
    D = int(input())
    P = [int(p_i) for p_i in input().split()]
    return best(tuple(sorted(P)))
    # return num_min(Counter(P))





def main():
    T = int(input())
    for t in range(T):
        print("Case #{}: {}".format(t+1, testcase()))


if __name__ == '__main__':
    main()
