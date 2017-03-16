#/usr/bin/env python3

from itertools import accumulate

def get_num_friends_needed(people):
    counts = ( int(x) - 1 for x in people )
    sums = accumulate(counts)
    m_val = min(sums)
    return -m_val if m_val < 0 else 0

T = int(input())
for t in range(T):
    s_max, people = input().split(" ")
    print("Case #" + str(t+1) + ": " + str(get_num_friends_needed(people)))
