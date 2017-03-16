#!/usr/bin/python3.4

import sys
import math
import copy

big_n = 0

known = {}

def solve2(ht):
    global big_n
    big_n +=1
    s = str(sorted(ht.items()))
    val = known.get(s, None)
    if val != None:
        return val

    s_sizes = sorted(ht.keys())

    nb_p_biggest = s_sizes[-1]
    nb_biggest = ht[nb_p_biggest]

    cur_min = nb_p_biggest
    if nb_biggest >= cur_min:   # takes too long to split
        return cur_min

    # Try split biggest
    max_split = (nb_p_biggest + 1) // 2

    ht.pop(nb_p_biggest)
    ht_orig = copy.deepcopy(ht)

    if nb_p_biggest % 2 == 0:
        mss = max_split + 1
    else:
        mss = max_split

    for split_size in reversed(range(2, mss)):
        ht[split_size]                = ht.get(split_size, 0)                + nb_biggest
        if ht[split_size] > split_size:
            ht[split_size] = split_size
        ht[nb_p_biggest - split_size] = ht.get(nb_p_biggest - split_size, 0) + nb_biggest
        if ht[nb_p_biggest - split_size] > nb_p_biggest - split_size:
            ht[nb_p_biggest - split_size] = nb_p_biggest - split_size
        t2 = solve2(ht) + nb_biggest

        if t2 < cur_min:
            cur_min = t2

        ht = copy.deepcopy(ht_orig)

    known[s] = cur_min

    return cur_min

def solve(stacks):
    missings = 0

    sys.setrecursionlimit(10000)

    # Make histogram:
    ht = {}
    for p in stacks:
        ht[p] = ht.get(p, 0) + 1

    for k in ht:
        if ht[k] > k:
            ht[k] = k

    return solve2(ht)

def main():
    nb = int(get_line())
    for case_id in range(1, nb + 1):
        d = int(get_line())

        stacks = [int(i) for i in get_line().split()]
        global big_n
        big_n = 0

        ret = solve(stacks)

        print('Case #%d: %s' % (case_id, ret), file = o)

###

def get_line():
    return f.readline().strip()

def open_files():
    if len(sys.argv) == 1:
        f = sys.stdin
        o = sys.stdout

    if len(sys.argv) == 2:
        f = open(sys.argv[1], 'r')
        o = sys.stdout

    if len(sys.argv) == 3:
        f = open(sys.argv[1], 'r')
        o = open(sys.argv[2], 'w')

    return (f, o)

if __name__ == "__main__":
    (f, o) = open_files()
    main()

