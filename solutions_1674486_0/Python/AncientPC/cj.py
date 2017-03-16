#!/usr/bin/env python2

from collections import defaultdict, deque
from multiprocessing import Pool, cpu_count
from functools import partial
import operator
import pudb

pool = Pool(processes = cpu_count())

def tree(): return defaultdict(tree)

nc = int(raw_input())
for c in xrange(nc):
    n = int(raw_input())

    # build tree
    t = tree()
    for i in xrange(1, n+1):
        data = map(int,raw_input().split())
        m = data[0]
        for j in xrange(1, len(data)):
            if i not in t:
                t[i] = []
            t[i].append(data[j])
    #print t

    # traverse tree
    diamond = False
    for i in xrange(1, n+1):
        if diamond: break
        if i not in t: pass
        touched = [0] * (n+1)
        queue = deque()
        queue.append(i)
        while len(queue) > 0:
            j = queue.popleft()
            for x in t[j]:
                if touched[x] == 0:
                    touched[x] += 1
                    queue.append(x)
                else:
                    diamond = True
                    break

    if diamond:
        print "Case #%d: %s" % (c+1, "Yes")
    else:
        print "Case #%d: %s" % (c+1, "No")
