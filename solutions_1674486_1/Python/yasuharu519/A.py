#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys, os
import operator
import itertools
from Queue import Queue as Q
TEMPLATE = "Case #%d: %s"

def decode(r):
    N = int(r.readline().rstrip())
    input_list = list()
    for i in range(N):
        input_list.append(map(int, r.readline().rstrip().split()))
    return (N, input_list)

def solve(N, Mset):
    q = Q()
    for i, data in enumerate(Mset):
        if data[0] >= 2:
            # print "Start", data[1:]
            q.put_nowait((i+1, data[1:]))
    ended = list()
    while(q.empty() is False):
        idx, data = q.get_nowait()
        q2 = Q()
        bad_number = list()
        for num in data:
            #print "put", num
            q2.put_nowait(num)
        while(q2.empty() is False):
            num = q2.get_nowait()
            if num == 0:
                continue
            #print "Bad", bad_number
            #print "Get", num
            if num in bad_number:
                return "Yes"
            else:
                bad_number.append(num)
                nums = Mset[num-1]
                if nums[0] != 0:
                    for i in nums[1:]:
                        q2.put_nowait(i)
                        # print "Q2 Put", i
    return "No"
        

if __name__ == "__main__":
    filename = sys.argv[1]
    with open(filename) as r:
        T = int(r.readline().rstrip())
        for i in xrange(T): 
            N, Mset = decode(r)
            print TEMPLATE % (i + 1, solve(N, Mset))
