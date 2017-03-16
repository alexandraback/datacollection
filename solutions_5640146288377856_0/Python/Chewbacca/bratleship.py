#! /usr/bin/env python3

import sys

def minc(R,C,W):
    # test every W-1 col
    N0 = 0
    for a in range(W-1,C,W):
        N0 += R
    if W==C:
        return N0 + C - 1
    if W==1:
        return N0
    return N0 + W - int(C%W==0)


number_of_test_cases = int(sys.stdin.readline())
for test_no in range(1, number_of_test_cases+1):
    R,C,W = map(int, sys.stdin.readline().split())
    print("Case #{}: {}".format(test_no,minc(R,C,W)))
