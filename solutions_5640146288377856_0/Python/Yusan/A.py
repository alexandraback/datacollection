#!/usr/bin/python
# vi: set fileencoding=utf-8 :


def minimum_score(R, C, W):
    if C % W == 0:
        return C / W - 1 + W
    else:
        return C / W + W


T = int(raw_input())
for case_number in range(1, T + 1):
    R, C, W = map(int, raw_input().split())
    print 'Case #%d: %d' % (case_number, minimum_score(R, C, W))
