#!/usr/bin/env python2

import os, sys
from Queue import Queue as queue

inputfile = 'i'
if len(sys.argv) > 1:
    inputfile = sys.argv[1]

f = open(inputfile, 'r')

T = int(f.readline()[:-1])

for t in range(T):
    s = f.readline()[:-1]
    n = int(s)
    fa = [[] for i in range(n+1)]
    ans = 0
    for i in range(n):
        s = f.readline()[:-1]
        ary = s.split(' ')
        fc = int(ary[0])
        for j in range(fc):
            fa[i+1].append(int(ary[j+1]))
    for i in range(1, n+1):
        if len(fa[i]) > 1:
            st = set(fa[i])
            q = queue()
            for j in fa[i]:
                q.put(j)
                while not q.empty():
                    cur = q.get()
                    for k in fa[cur]:
                        if st.issuperset({k}):
                            ans = 1
                            break
                        st.add(k)
                        q.put(k)
                    if ans == 1: break
                if ans == 1: break
        if ans == 1: break
    print 'Case #%d: %s' % (t+1, ans == 1 and "Yes" or 'No')
