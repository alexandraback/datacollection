#!/usr/bin/env python
import sys
def read_line(): return sys.stdin.readline().strip()
def read_int(): return int(sys.stdin.readline())
def read_ints(): return [int(x) for x in sys.stdin.readline().split()]

def solve():
    # Read a problem
    A, N = read_ints()
    motes = read_ints()
    motes.sort()

    min_count = N
    feed_count = 0
    cur_size = A

    while len(motes) > 0:
        if cur_size > motes[0]:
            cur_size += motes.pop(0)
            min_count = min(min_count, feed_count + len(motes))
            continue
        else:
            cur_size += cur_size - 1
            feed_count += 1
            if feed_count >= N:
                break

    return (min_count,)

if __name__ == '__main__':
    N = read_int()
    for i in range(N):
        print('Case #{}: '.format(i+1) + ' '.join(map(str, solve())))
