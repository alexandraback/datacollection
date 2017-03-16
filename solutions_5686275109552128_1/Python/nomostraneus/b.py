

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
        D = int(raw_input())
        P = map(int, raw_input().split())
        m = max(P)
        u = min([t + sum([(p-1) / t for p in P]) for t in xrange(1, m+1)])

        print("Case #%i: %d"% (caseNr + 1, u))
