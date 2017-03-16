#!/usr/bin/python3

T = int(input())
for case in range(T):
    # maxS = int(input())
    s = input().split()[1]
    cur_sum = 0
    add = 0
    for i in range(len(s)):
        level = int(s[i])
        if cur_sum < i:
            add += i - cur_sum
            cur_sum += i - cur_sum
        cur_sum += level
    print ("Case #%d: %d" % (case + 1, add))
