#!/usr/bin/env python
#-*- coding: utf-8 -*-

from collections import defaultdict
from math import factorial as f
from fractions import gcd as g
from fractions import Fraction as F
import math

T = int (raw_input ())
for t in range (1, T + 1):
    a, b = [int (i) for i in raw_input ().split ('/')]
    x = F (a, b)
    ret = 0
    cnt = 1
    for i in range (100005):
        if F (cnt * a, b) >= F (1, 1):
            break
        ret += 1
        cnt *= 2
    if x.denominator != 2 ** int (math.log (x.denominator, 2)): ret = -1
    if ret != -1: print ("Case #{0}: {1}".format (t, ret))
    else: print ("Case #{0}: impossible".format (t))
