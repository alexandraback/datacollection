#!/usr/bin/python

from __future__ import division

import sys, os, subprocess

def line():
    return FD.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d: %s' % (i+1, go())

def go():
    C,F,X = map(float, line().split())
    t = 0
    rate = 2
    lastbuynow = float('+inf')
    while True:
        buynow = t + X / rate
        #print>>sys.stderr, 'now: %s' % buynow
        if buynow > lastbuynow:
            return lastbuynow
        lastbuynow = buynow
        t += C / rate
        rate += F
        #print>>sys.stderr, 'Bought, t=%s, r=%s' % (t, rate)

def main():
    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]

    root = fn[:-2]
    with open(fn) as fd:
        global FD
        FD = fd
        backupstdout = sys.stdout
        sys.stdout = open(root+'result', 'wb')
        doit()
        sys.stdout = backupstdout
        subprocess.call(['diff', '-du', root+'out', root+'result'])

if __name__ == '__main__':
    main()
