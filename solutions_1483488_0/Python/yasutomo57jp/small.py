#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys
import math
import itertools
from multiprocessing import Pool


def f(line_str):
    a_str,b_str=line_str.split(" ")
    ndigit=len(a_str)
    a=int(a_str)
    b=int(b_str)
    a_chars=map(int,list(a_str))
    b_chars=map(int,list(b_str))

    results=set([])
    used=set([])
    for v in range(a,b+1):
        if v in used:continue
        v_chars=map(int,list(str(v)))
        vs=set([v])
        for j in range(ndigit-1):
            v_chars=[v_chars.pop()]+v_chars

            if v_chars[0]==0:continue
            val=int("".join(map(str,v_chars)))
            used.add(val)
            vs.add(val)

        vs=filter(lambda x: a<=x and x<=b, vs)
        if len(vs)<2: continue

        for w in itertools.combinations(vs,2):
            results.add(w)

    return "%d" % (len(results))

lines=int(sys.stdin.readline().strip())
line_strs=[]
for i in range(lines):
    line_strs.append(sys.stdin.readline().strip())

p=Pool(8)
result=p.map(f, line_strs)

for i,r in enumerate(result):
    print "Case #%d: %s" % (i+1, r)

