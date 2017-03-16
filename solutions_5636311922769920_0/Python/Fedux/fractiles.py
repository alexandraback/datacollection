#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser

def transform(pos, k, offset):
    assert offset < k
    return pos * k + offset

def transform_seq(k, offset_seq):
    pos = 0
    for c, offset in enumerate(offset_seq, 1):
        pos = transform(pos, k, offset)
        assert 0 <= pos < k ** c
    return pos

def solve(k, c, s):
    if s * c < k:
        return False
    else:
        positions = []
        first_unknown = 0
        for i in range(s):
            if first_unknown >= k:
                break
            offset_seq = range(first_unknown, first_unknown + c)
            assert offset_seq[0] == first_unknown
            assert offset_seq[-1] == first_unknown + c - 1
            assert len(offset_seq) == c
            offset_seq = [min(x, k-1) for x in offset_seq]
            positions.append(transform_seq(k, offset_seq))
            first_unknown += c
        return positions

inputfile = FileParser()
T = inputfile.read_int()
for test in range(1, T+1):
    K, C, S = inputfile.read_integers()

    result = solve(K, C, S)

    if result:
        print "Case #{}: {}".format(test, " ".join([str(x+1) for x in result]))
    else:
        print "Case #{}: IMPOSSIBLE".format(test)
