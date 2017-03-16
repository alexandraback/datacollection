#!/usr/bin/env python
# Wentao Han (wentao.han@gmail.com)

import sys
import string

"""
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand

rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities

de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
"""

TABLE = string.maketrans('abcdefghijklmnopqrstuvwxyz',
                         'yhesocvxduiglbkrztnwjpfmaq')

T = int(sys.stdin.readline().strip())
for X in range(1, T + 1):
    G = sys.stdin.readline().strip()
    S = G.translate(TABLE)
    sys.stdout.write('Case #%d: %s\n' % (X, S))
