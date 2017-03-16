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
    D = int(line())
    stacks = map(int, line().split())
    assert len(stacks) == D

    stacks.append(0)

    best = max(stacks)

    stacks.sort(reverse=True)

    for maxstackafterspecial in range(1, max(stacks)+1):
        M = maxstackafterspecial
        minneeded = 0
        for s in stacks:
            stapels = (s + M - 1) // M
            extramins = max(stapels-1,0)
            minneeded += extramins
            #print 'M=%d, voor s=%d, %d mins nodig' % (M,s,extramins)

        #print 'M=%d + minneeded=%d = %d' % (M, minneeded, M+minneeded)
        best = min(best, M + minneeded)
    return best

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
        sys.stdout = open(root+'out', 'wb')
        doit()
        sys.stdout = backupstdout
        subprocess.call(['diff', '-sdu', root+'good', root+'out'])

if __name__ == '__main__':
    main()
