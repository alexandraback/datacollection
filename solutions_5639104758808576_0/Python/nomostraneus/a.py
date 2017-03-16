

#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import sys
import itertools as it
import re
import collections
from operator import mul
from operator import itemgetter
import heapq


if __name__ == "__main__":
    testcases = input()

    for caseNr in xrange(testcases):
        [N, S] = raw_input().split()
        S = [int(s) for s in S]

        def psum(S):
            s = 0
            for a in S:
                yield s
                s += a

        inv = max([i - s if s < i else 0 for i, s in enumerate(list(psum(S)))])


        print("Case #%i: %d"% (caseNr + 1, inv))
