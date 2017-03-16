__author__ = 'deniskrut'

import sys

t = int(sys.stdin.readline())

vowels_arr = ['a', 'e', 'i', 'o', 'u']
vowels = set(vowels_arr)

for i in range(0, t):
    line_arr = sys.stdin.readline().split()
    word = line_arr[0]
    n = int(line_arr[1])
    count = 0
    cur_len = 0
    base_valid_groups = set()
    for ind in range(0, len(word)):
        smb = word[ind]
        if smb in vowels:
            cur_len = 0
        else:
            cur_len += 1
        if cur_len >= n:
            base_valid_groups.add((ind - n + 1, n))
    all_valid_groups = set(base_valid_groups)
    for valid_group in base_valid_groups:
        gr_start = valid_group[0]
        gr_len = valid_group[1]
        for new_first in range(0, gr_start + 1):
            for new_last in range(gr_start + gr_len - 1, len(word)):
                all_valid_groups.add((new_first, new_last - new_first + 1))
            #all_valid_groups.add((new_start, gr_start - new_start + gr_len))
        #for k in range(gr_start + gr_len + 1, len(word)):
            #all_valid_groups.add((gr_start, k - gr_start))
    print "Case #" + str(i + 1) + ": " + str(len(all_valid_groups))