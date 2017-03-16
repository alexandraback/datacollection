#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np

def solver(lists):
    heights = np.array(lists)
    unique_heights = np.unique(heights)
    cnt = [np.count_nonzero(heights == i) for i in unique_heights]
    cnt = np.array(cnt)

    assert (sum(cnt) == 2 * n ** 2 - n)
    idx = cnt % 2  # find odd numbers
    missing_heights = unique_heights[idx == 1]
    missing_heights = np.sort(missing_heights)
    assert (missing_heights.size == n)
    return missing_heights

if __name__ == "__main__":

    testcases = input()
    for caseNr in xrange(1, testcases+1):
        n = input()
        lists = []
        for i in xrange(2*n-1):
            list = raw_input().split()
            list = [int(l) for l in list]
            lists.append(list)
        missing_heights = solver(lists)
        p = ' '.join(map(str, missing_heights))
        print "Case #%d: %s" % (caseNr, p)