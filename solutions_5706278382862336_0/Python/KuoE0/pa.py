#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.

"""

"""

import fractions
import math

T = input()

for t in xrange(T):

    P, Q = [int(x) for x in raw_input().split('/')]

    gcd = fractions.gcd(P, Q)

    if gcd != 1:
        P /= gcd
        Q /= gcd

    e = int(math.log(Q, 2))

    if 2 ** e != Q:
        print "Case #{0}: impossible".format(t + 1)
    else:
        print "Case #{0}: {1}".format(t + 1, int(math.ceil(math.log(float(Q) / P, 2))))









