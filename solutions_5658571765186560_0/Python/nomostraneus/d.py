

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
        [X, R, C] = map(int, raw_input().split())
        if R > C:
            R, C = C, R

        if X >= 7:
            win = True
        elif (R*C) % X != 0:
            win = True
        elif X == 1:
            win = False
        elif X == 2:
            win = False
        elif X == 3:
            if R == 1:
                win = True
            else:
                win = False
        elif X == 4:
            if R <= 2:
                win = True
            else:
                win = False
        elif X == 5:
            if R <= 2:
                win = True
            elif R == 3 and C == 5:
                win = True
            else:
                win = False
        elif X == 6:
            if R <= 3:
                win = True
            else:
                win = False
        print("Case #%i: %s"% (caseNr + 1, "GABRIEL" if not win else "RICHARD"))
