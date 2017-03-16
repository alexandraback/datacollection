#!/usr/bin/env pypy
import math
import sys
from collections import deque

def compute_result(A, mote_sizes):
    curr_size = A
    choice_tree = []
    N = len(mote_sizes)
    if curr_size == 1:
        return N
    for i, size in enumerate(mote_sizes):
        if curr_size > size:
            curr_size += size
        else:
            poss_moves = int(math.log((size-1)//(curr_size-1), 2)) + 1
            kill_all = N - i
            choice_tree.append((poss_moves, kill_all))
            curr_size = (2**poss_moves)*(curr_size-1)+1
            assert curr_size > size
            curr_size += size
    curr_min = 0
    for poss_moves, kill_all in reversed(choice_tree):
        curr_min = min(poss_moves+curr_min, kill_all)
    return curr_min

def main():
    fname, gname = sys.argv[1:]
    with open(fname) as f, open(gname, 'w') as g:
        # number of test cases
        T = int(f.readline().strip())
        for i in xrange(T):
            # size of Armin's mote, and number of other motes
            A, N = map(int, f.readline().strip().split())
            mote_sizes = deque(sorted(map(int, f.readline().strip().split())))
            result = compute_result(A, mote_sizes)
            g.write("Case #{0}: {1}\n".format(i+1, result))

if __name__ == "__main__":
    status = main()
    sys.exit(status)
