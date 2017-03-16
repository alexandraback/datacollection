#!/usr/bin/python
import sys

ipfile = sys.stdin
opfile = sys.stdout
sleep = set(map(str,range(0,10)))

T = int(ipfile.readline().strip())
for t in xrange(1,T+1):
    N = int(ipfile.readline().strip())
    if N == 0:
        opfile.write('Case #%d: INSOMNIA\n' % (t,))
        continue
    i = 0
    count = set()
    done = False
    for i in xrange(1,73):
        n = N*i
        ns = str(n)
        count.update(ns)
        if sleep == count:
            done = True
            opfile.write('Case #%d: %d\n' % (t,n))
            break
    if not done:
        opfile.write('Case #%d: INSOMNIA\n' % (t,))
        
