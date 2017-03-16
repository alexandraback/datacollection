#!/usr/bin/env python
# -*- coding: utf-8 -*-
import re
import sys
import os
import time
import itertools
import collections

def main():
    n = int(raw_input())
    for nn in range(n):
        c,f,x = map(float, raw_input().strip().split())
        ans = 1.*x/2;
        m = 0
        now = 0
        y = 0
        while now < ans:
            #buy one more
            t = 1.0 * c / (2+m*f)

            #rest after by machine
            tt = now + t + 1. * x / (2+m*f + f)

            if tt < ans:
                ans = tt

            now = now + t
            m+=1

        print "Case #%d: %s" % (nn+1, ans)



if __name__ == '__main__':
    main()
