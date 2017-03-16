#!/usr/bin/python3

import sys

T = int(sys.stdin.readline())

for i in range(1, T+1):
    K, C, S = [int(x) for x in sys.stdin.readline().split()]
    # K == S
    print('Case #{0}: '.format(i) + ' '.join(str(x) for x in range(1, S+1)))
