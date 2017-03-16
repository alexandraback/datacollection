#!/usr/bin/env python
import sys
def read_line(): return sys.stdin.readline().strip()
def read_int(): return int(sys.stdin.readline())
def read_ints(): return [int(x) for x in sys.stdin.readline().split()]

def is_conso(ch):
    return ch != 'a' and ch != 'i' and ch != 'u' and ch != 'e' and ch != 'o'

def solve():
    # Read a problem
    name, n = sys.stdin.readline().split()
    n = int(n)
    name_len = len(name)

    conso_counts = [0] * name_len
    if is_conso(name[0]):
        conso_counts[0] = 1
    for i in range(1, name_len):
        if is_conso(name[i]):
            conso_counts[i] = conso_counts[i-1] + 1
        else:
            conso_counts[i] = 0

    count = 0
    last_match_pos = -1
    for i in range(n - 1, name_len):
        if conso_counts[i] >= n:
            first = i - n + 1 - last_match_pos
            last = name_len - i
            count += first * last
            last_match_pos = i - n + 1

    return (count,)

if __name__ == '__main__':
    N = read_int()
    for i in range(N):
        print('Case #{}: '.format(i+1) + ' '.join(map(str, solve())))
